-- 자동차 종류가 '세단'인 자동차들
-- 10월에 대여를 시작한 기록이 있는 자동차 ID 리스트
-- 자동차 ID 리스트는 중복이 없어야 하며
-- 자동차 ID를 기준으로 내림차순
SELECT Distinct(A.CAR_ID)
FROM CAR_RENTAL_COMPANY_CAR A JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY B
ON A.CAR_ID = B.CAR_ID
WHERE A.CAR_TYPE = '세단' AND TO_CHAR(B.START_DATE, 'MM') = '10'
ORDER BY 1 DESC;