import { Router } from "express";
import {
  query,
  validationResult,
  body,
  matchedData,
  checkSchema,
} from "express-validator";
import { createUserValidationSchema } from "../utils/validationSchemas.js";
import { mockUsers } from "../utils/constants.js";
import { resolveIndexByUserId } from "../utils/middlewares.js";

const router = Router();

export const myValidationResult = validationResult.withDefaults({
  formatter: (error) => error.msg,
});

router.get(
  "/api/users",
  query("filter")
    .isString()
    .notEmpty()
    .withMessage("Must not be empty")
    .isLength({ min: 3, max: 10 })
    .withMessage("Must be at least 3-10 characters"),
  (req, res) => {
    const {
      query: { filter, value },
    } = req;
    if (filter && value) {
      return res.send(mockUsers.filter((user) => user[filter].includes(value)));
    }
    return res.send(mockUsers);
  }
);

router.get("/api/users/:id", resolveIndexByUserId, (req, res) => {
  const { findUserIndex } = req;
  const findUser = mockUsers[findUserIndex];
  if (!findUser) return res.sendStatus(404);
  return res.send(findUser);
});

router.post(
  "/api/users",
  checkSchema(createUserValidationSchema),
  (req, res) => {
    const result = myValidationResult(req);
    if (!result.isEmpty()) {
      return res.status(400).send({ errors: result.array() });
    }

    const data = matchedData(req);
    const newUser = { id: mockUsers[mockUsers.length - 1].id + 1, ...data };
    mockUsers.push(newUser);
    return res.status(201).send(newUser);
  }
);

router.put("/api/users/:id", resolveIndexByUserId, (req, res) => {
  const { body, findUserIndex } = req;
  const data = matchedData(req);
  mockUsers[findUserIndex] = { id: mockUsers[findUserIndex].id, ...data };
  return res.sendStatus(200);
});

router.delete("/api/users/:id", resolveIndexByUserId, (req, res) => {
  const { findUserIndex } = req;
  mockUsers.splice(findUserIndex, 1);
  return res.sendStatus(200);
});

router.patch("/api/users/:id", resolveIndexByUserId, (req, res) => {
  const { body, findUserIndex } = req;
  mockUsers[findUserIndex] = { ...mockUsers[findUserIndex], ...body };
  return res.sendStatus(200);
});

export default router;
