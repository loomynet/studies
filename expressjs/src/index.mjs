import { PORT } from "./config/config.mjs";
import express, { response } from "express";

const app = express();

const mockUsers = [
  { id: 1, username: "anson", displayName: "Anson" },
  { id: 2, username: "jack", displayName: "Jack" },
  { id: 3, username: "adam", displayName: "Adam" },
];

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});

app.get("/api", (req, res) => {
  res.status(200).send({ msg: "Hello" });
});

app.get("/api/users", (req, res) => {
  res.send(mockUsers);
});

app.get("/api/users/:id", (req, res) => {
  const parsedId = parseInt(req.params.id);
  if (isNaN(parsedId)) {
    return res.status(400).send({ msg: "Bad request. Invalid Id." });
  }
  const findUser = mockUsers.find((user) => user.id === parsedId);
  if (!findUser) {
    return res.sendStatus(404);
  } else {
    return res.send(findUser);
  }
});

app.get("/api/products", (req, res) => {
  res.send([{ id: 123, name: "chicken breast", price: 12.99 }]);
});
