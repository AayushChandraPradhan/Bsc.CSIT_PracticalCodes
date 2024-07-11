-- import this in phpmyadmin, these are the steps

-- Open phpMyAdmin.
-- Click on the "Import" tab.
-- Choose the crud_db.sql file.
-- scroll down and Click "Go" to import the file.

CREATE DATABASE crud_db;
USE crud_db;

CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    branch VARCHAR(50) NOT NULL,
    cgpa DECIMAL(3, 2) NOT NULL
);
