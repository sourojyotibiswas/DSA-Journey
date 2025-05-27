-- Employees earning more than their managers

-- Table: Employee
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- | salary      | int     |
-- | managerId   | int     |
-- +-------------+---------+

SELECT E.name AS Employee
FROM Employee E
JOIN Employee M ON E.managerId = M.id
WHERE E.salary > M.salary;