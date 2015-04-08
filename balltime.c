#include <stdio.h>
#include <stdlib.h>
#include "head.h" 

int Is_true_Queue(LinkQueue *q)
{
    int i = 1;
    //跳过头节点
    LinkNode *p = q->front->next;
    for (i = 1; i <= 27; i++)
    {
        if (p->data != i)
            return 0;
        p = p->next;
    }
    return 1;
}

int ball_time(LinkQueue *ball_Lq,LinkStack *ball_1_mLs,LinkStack *ball_5_mLs,LinkStack *ball_1_hLs)
{
    int t=0;
    int ball;
    int ball_last;
    int day = 0;

    while (1)
    {
        while (ball_1_hLs->n != 12)
        {
            while (ball_5_mLs->n != 11)
            {
                while (ball_1_mLs->n != 4)
                {
                    ball = delete_linkqueue(ball_Lq);
                    push_linkstack(ball_1_mLs,ball);
                }
                while (!is_empty_linkstack(ball_1_mLs))
                {
                    ball = pop_linkstack(ball_1_mLs);
                    enter_linkqueue(ball_Lq,ball);
                }

                ball = delete_linkqueue(ball_Lq);
                printf("%d======\n",t++);
                push_linkstack(ball_5_mLs,ball);
            }
            while (!is_empty_linkstack(ball_5_mLs))
            {
                ball = pop_linkstack(ball_5_mLs);
                enter_linkqueue(ball_Lq,ball);
            }

            ball = delete_linkqueue(ball_Lq);
            push_linkstack(ball_1_hLs,ball);
            day++;
            if (ball_1_hLs->n == 12)
            {
                ball_last = pop_linkstack(ball_1_hLs);
                while (!is_empty_linkstack(ball_1_hLs))
                {
                    ball = pop_linkstack(ball_1_hLs);
                    enter_linkqueue(ball_Lq,ball);
                }
                enter_linkqueue(ball_Lq,ball_last);

                if (Is_true_Queue(ball_Lq))
                    return day/2;
            }
        }
    }
    return 0;
}
int main()
{
    int day = 0;
    LinkQueue *ball_Lq = create_linkqueue();
    LinkStack *ball_1_mLs = create_empty_linkstack();
    LinkStack *ball_5_mLs = create_empty_linkstack();
    LinkStack *ball_1_hLs = create_empty_linkstack();

    day = ball_time(ball_Lq,ball_1_mLs,ball_5_mLs,ball_1_hLs);

    printf("day = %d\n",day);
    return 0;
}
