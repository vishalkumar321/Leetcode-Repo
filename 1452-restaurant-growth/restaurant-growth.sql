# Write your MySQL query statement below
with daily as (
    select visited_on,
    sum(amount) as amount
    from customer
    group by visited_on
),
moving as (
    select visited_on,

    sum(amount) over (
        order by visited_on
        rows between 6 preceding and current row
    ) as amount,

    round(
        avg(amount) over (
            order by visited_on
            rows between 6 preceding and current row
        ), 2
    ) as average_amount,

    row_number() over (
        order by visited_on
    ) as rn

    from daily
)
select visited_on, amount, average_amount
from moving
where rn>=7
order by visited_on;