CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M = N-1;
  RETURN (
      IFNULL((
      SELECT distinct salary from Employee
      ORDER BY salary DESC LIMIT 1 OFFSET M), NULL)
  );
END