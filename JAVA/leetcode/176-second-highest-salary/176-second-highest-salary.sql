# Write your MySQL query statement below
SELECT MAX(emp1.salary) AS SecondHighestSalary from Employee emp1
WHERE emp1.salary != (SELECT MAX(emp2.salary) from Employee emp2);