-- Recyclable and low fat products

SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';