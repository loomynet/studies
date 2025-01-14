import { PORT } from "./config/config.js";
import { secret } from "./config/config.js";
import express from "express";
import routes from "./routes/index.js";
import cookieParser from "cookie-parser";
import session from "express-session";
import { mockUsers } from "./utils/constants.js";
import passport from "passport";
import "./strategies/local-strategy.js";

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
app.use(passport.initialize());
app.use(passport.session());
app.use(routes);

app.post("/api/auth", passport.authenticate("local"), (req, res) => {
  res.sendStatus(200);
});

app.get("/api/auth/status", (req, res) => {
  return req.user ? res.send(req.user) : res.sendStatus(401);
});

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});
