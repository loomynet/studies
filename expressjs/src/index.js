import { PORT } from "./config/config.js";
import { secret } from "./config/config.js";
import express from "express";
import routes from "./routes/index.js";
import cookieParser from "cookie-parser";
import session from "express-session";
import { mockUsers } from "./utils/constants.js";

const app = express();

app.use(express.json());
app.use(cookieParser());
app.use(
  session({
    secret: secret,
    saveUninitialized: false,
    resave: false,
    cookie: {
      maxAge: 60000 * 60,
    },
  })
);
app.use(routes);

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});

app.get("/api", (req, res) => {
  res.cookie("hello", "world", { maxAge: 60000 * 60 * 2 });
  res.status(200).send({ msg: "Hello" });
});

app.post("/api/auth", (req, res) => {
  const {
    body: { username, password },
  } = req;
  const findUser = mockUsers.find((user) => user.username === username);
  if (!findUser || findUser.password !== password)
    return res.status(401).send({ msg: "Bad credentials" });

  req.session.user = findUser;
  return res.status(200).send(findUser);
});

app.get("/api/auth/status", (req, res) => {
  req.sessionStore.get(req.sessionID, (err, session) => {
    console.log(session);
  });
  return req.session.user
    ? res.status(200).send(req.session.user)
    : res.status(401).send({ msg: "Not authenticated" });
});
