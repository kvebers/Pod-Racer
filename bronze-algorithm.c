#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int cnt = 0;
    int sharp_turn = 0;
    int boosted = 0;
    int check_point = 0;
    int temp = 0;
    // game loop
    while (1) {
        int x;
        int y;        // x position of the next check point
        int next_checkpoint_x;
        // y position of the next check point
        int next_checkpoint_y;
        // distance to the next checkpoint
        int next_checkpoint_dist;
        // angle between your pod orientation and the direction of the next checkpoint
        int next_checkpoint_angle;
        scanf("%d%d%d%d%d%d", &x, &y, &next_checkpoint_x, &next_checkpoint_y, &next_checkpoint_dist, &next_checkpoint_angle);
        int opponent_x;
        int opponent_y;
        scanf("%d%d", &opponent_x, &opponent_y);
        int thrust;

        int delta_x;
        int delta_y;
        int shortest_x;
        int shortest_y;
        int delta_distance;
        int sharp_turn;
        int delta_op_x;
        int delta_op_y;
        int enemy_distance;

        delta_op_x = next_checkpoint_x - opponent_x;
        delta_op_y = next_checkpoint_y - opponent_y;
        enemy_distance = sqrt(pow(delta_op_x, 2) + pow(delta_op_y, 2)); 

        delta_x = next_checkpoint_angle - x;
        delta_y = next_checkpoint_angle - y;
        delta_distance = 200 / next_checkpoint_dist;
        shortest_x = delta_x *  delta_distance;
        shortest_y = delta_y * delta_distance;
        
        if (temp != next_checkpoint_x)
        {
            if (next_checkpoint_angle > 120 || next_checkpoint_angle < -120)
            {
                sharp_turn = 3;
                thrust = 0;
                printf("%d %d %i\n", next_checkpoint_x, next_checkpoint_y, thrust);
                continue;
            }
        }     
        if (sharp_turn == 3)
        {
            sharp_turn = 2;
            thrust = 80;
            printf("%d %d %i\n", next_checkpoint_x, next_checkpoint_y, thrust);
            continue;
        }
        if (sharp_turn == 2)
        {
            sharp_turn = 1;
            thrust = 10;
            printf("%d %d %i\n", next_checkpoint_x, next_checkpoint_y, thrust);
            continue;
        }
        
        
        temp = next_checkpoint_x;

        if (boosted == 0 && (enemy_distance < next_checkpoint_dist) && (next_checkpoint_dist > 1800) && (thrust == 100) && (next_checkpoint_angle < 25 && next_checkpoint_angle > -25))
        {        
            printf("%d %d BOOST\n", next_checkpoint_x + shortest_x, next_checkpoint_y + shortest_y);
            boosted = 1;
            continue;
        }
        if (sharp_turn == 1)
        {
            thrust = 100;
            sharp_turn = 0;
            printf("%d %d %i\n", next_checkpoint_x, next_checkpoint_y, thrust);
            continue;
        }
        if (next_checkpoint_dist < 100)
        {
            sharp_turn = 1;
        }
        if (next_checkpoint_angle > 90 || next_checkpoint_angle < -90)
        {
            thrust = 10;
            sharp_turn = 1;
        }
        else if (next_checkpoint_angle > 40 || next_checkpoint_angle < -40)
        {
            thrust = 10;
            sharp_turn = 1;
        }
        else
        {
            thrust = 100;
        }
        printf("%d %d %i\n", next_checkpoint_x - shortest_x , next_checkpoint_y - shortest_y, thrust);
    cnt++;
    }
    return (0);
}

