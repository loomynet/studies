import { Router } from "express";

const router = Router();

router.get("/api/products", (req, res) => {
  console.log(req.cookies);
  if (req.cookies.hello && req.cookies.hello === "world") {
    return res.send([{ id: 123, name: "chicken breast", price: 12.99 }]);
  }
  return res.status(401).send({ msg: "Sorry, you need the correct cookie." });
});

export default router;
