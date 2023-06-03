SELECT ORDER_ID, PRODUCT_ID, to_char(OUT_DATE, 'yyyy-mm-dd'), case when to_char(OUT_DATE, 'yyyy-mm-dd') <= '2022-05-01' then '출고완료' when to_char(OUT_DATE, 'yyyy-mm-dd') > '2022-05-01' then '출고대기' when  OUT_DATE is null then '출고미정' end 출고여부
FROM FOOD_ORDER
ORDER BY 1 asc;