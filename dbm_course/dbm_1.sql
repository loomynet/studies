CREATE TABLE "Lecturer" (
  "Staff_id" integer PRIMARY KEY,
  "Staff_Fname" varchar,
  "Staff_Lname" varchar,
  "Staff_degree" varchar
);

CREATE TABLE "Course" (
  "Course_code" integer PRIMARY KEY,
  "Course_title" varchar,
  "Course_credit" integer
);

CREATE TABLE "Program" (
  "Program_code" integer PRIMARY KEY,
  "Program_title" varchar,
  "Program_duration" integer
);

CREATE TABLE "Course_Lecturer" (
  "Course_Course_code" integer,
  "Lecturer_Staff_id" integer,
  PRIMARY KEY ("Course_Course_code", "Lecturer_Staff_id")
);

ALTER TABLE "Course_Lecturer" ADD FOREIGN KEY ("Course_Course_code") REFERENCES "Course" ("Course_code");

ALTER TABLE "Course_Lecturer" ADD FOREIGN KEY ("Lecturer_Staff_id") REFERENCES "Lecturer" ("Staff_id");


CREATE TABLE "Course_Program" (
  "Course_Course_code" integer,
  "Program_Program_code" integer,
  PRIMARY KEY ("Course_Course_code", "Program_Program_code")
);

ALTER TABLE "Course_Program" ADD FOREIGN KEY ("Course_Course_code") REFERENCES "Course" ("Course_code");

ALTER TABLE "Course_Program" ADD FOREIGN KEY ("Program_Program_code") REFERENCES "Program" ("Program_code");


CREATE TABLE "Lecturer_Program" (
  "Lecturer_Staff_id" integer,
  "Program_Program_code" integer,
  PRIMARY KEY ("Lecturer_Staff_id", "Program_Program_code")
);

ALTER TABLE "Lecturer_Program" ADD FOREIGN KEY ("Lecturer_Staff_id") REFERENCES "Lecturer" ("Staff_id");

ALTER TABLE "Lecturer_Program" ADD FOREIGN KEY ("Program_Program_code") REFERENCES "Program" ("Program_code");

