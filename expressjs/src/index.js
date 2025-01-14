import { PORT } from "./config/config.js";
import express from "express";
import routes from "./routes/index.js";
import cookieParser from "cookie-parser";

const app = express();

app.use(express.json());
app.use(cookieParser());
app.use(routes);

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});

app.get("/api", (req, res) => {
  res.cookie("hello", "world", { maxAge: 60000 * 60 * 2 });
  res.status(200).send({ msg: "Hello" });
});
