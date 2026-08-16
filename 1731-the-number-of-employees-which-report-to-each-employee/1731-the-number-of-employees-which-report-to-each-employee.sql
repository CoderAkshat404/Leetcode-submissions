SELECT 
    reports_to AS employee_id,
    (SELECT name 
     FROM Employees e2 
     WHERE e2.employee_id = e1.reports_to) AS name,
    COUNT(employee_id) AS reports_count,
    ROUND(AVG(age)) AS average_age
FROM Employees e1
WHERE reports_to IS NOT NULL
GROUP BY reports_to order by employee_id