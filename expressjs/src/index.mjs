import { PORT } from "./config/config.mjs";
import express from "express";

const app = express();

app.use(express.json());

const mockUsers = [
  { id: 1, username: "anson", displayName: "Anson" },
  { id: 2, username: "jack", displayName: "Jack" },
  { id: 3, username: "adam", displayName: "Adam" },
  { id: 4, username: "linda", displayName: "Linda" },
  { id: 5, username: "mike", displayName: "Mike" },
  { id: 6, username: "matt", displayName: "Matt" },
  { id: 7, username: "nick", displayName: "Nick" },
];

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});

app.get("/api", (req, res) => {
  res.status(200).send({ msg: "Hello" });
});

app.get("/api/users", (req, res) => {
  // Same as
  // const filter = req.query.filter;
  // const value = req.query.value;
  const {
    query: { filter, value },
  } = req;

  if (filter && value)
    return res.send(mockUsers.filter((user) => user[filter].includes(value)));
  return res.send(mockUsers);
});

app.post("/api/users", (req, res) => {
  console.log(req.body);
  // const body = req.body;
  const { body } = req;
  const newUser = { id: mockUsers[mockUsers.length - 1].id + 1, ...body };
  mockUsers.push(newUser);
  return res.status(201).send(newUser);
});

app.get("/api/users/:id", (req, res) => {
  const parsedId = parseInt(req.params.id);
  if (isNaN(parsedId)) {
    return res.status(400).send({ msg: "Bad request. Invalid Id." });
  }

  const findUser = mockUsers.find((user) => user.id === parsedId);
  if (!findUser) return res.sendStatus(404);
  return res.send(findUser);
});

app.get("/api/products", (req, res) => {
  res.send([{ id: 123, name: "chicken breast", price: 12.99 }]);
});

app.put("/api/users/:id", (req, res) => {
  const {
    body,
    params: { id },
  } = req;

  const parsedId = parseInt(id);
  if (isNaN(parsedId)) return res.sendStatus(400);

  const findUserIndex = mockUsers.findIndex((user) => user.id === parsedId);

  if (findUserIndex === -1) return res.statusCode(404);
  mockUsers[findUserIndex] = { id: parsedId, ...body };
  return res.sendStatus(200);
});
