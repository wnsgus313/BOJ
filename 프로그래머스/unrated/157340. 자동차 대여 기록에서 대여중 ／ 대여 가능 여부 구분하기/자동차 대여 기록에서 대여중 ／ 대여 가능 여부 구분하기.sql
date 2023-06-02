-- 2022년 10월 16일에 대여 중인 자동차인 경우 '대여중' 이라고 표시
-- 대여 중이지 않은 자동차인 경우 '대여 가능'을 표시
-- 반납 날짜가 2022년 10월 16일인 경우에도 '대여중'으로 표시
SELECT CAR_ID, case when sum(state) = 1 then '대여중' else '대여 가능' end AVAILABILITY
FROM (
    select CAR_ID,
        (
            case when to_date('20221016', 'YYYY-MM=DD') between START_DATE and END_DATE then 1
            else 0
            end
        ) state
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
)
Group by CAR_ID

ORDER BY 1 DESC