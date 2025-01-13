import { PORT } from "./config/config.js";
import express from "express";
import routes from "./routes/index.js";

const app = express();

app.use(express.json());
app.use(routes);

app.listen(PORT, () => {
  console.log(`Listening at: http://localhost:${PORT}`);
});

app.get("/api", (req, res) => {
  res.status(200).send({ msg: "Hello" });
});
