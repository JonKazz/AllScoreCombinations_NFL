#include <stdio.h>

// Recursive function to find all possible combinations of scoring plays
// score: current score to be matched
// lastplay: the last scoring play used (to avoid duplicates)
// td2pt: count of touchdowns + 2-point conversions (8 points)
// td1pt: count of touchdowns + fieldgoal (7 points)
// td: count of regular touchdowns (6 points)
// fg: count of field goals (3 points)
// safety: count of safeties (2 points)
void findscores(int score, int lastplay, int td2pt, int td1pt, int td, int fg, int safety)
{

    // Base case: if the score becomes negative, stop (invalid score).
    if (score < 0)
    {
        return;
    }

    // Base case: if the score is exactly 0, print the combination of plays.
    if (score == 0)
    {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
        return;
    }

    // Try scoring with a touchdown + 2-point conversion (8 points)
    findscores(score - 8, 8, td2pt + 1, td1pt, td, fg, safety);

    // Try scoring with a touchdown + fieldgoal (7 points)
    if (lastplay <= 7)
    {
        findscores(score - 7, 7, td2pt, td1pt + 1, td, fg, safety);
    }

    // Try scoring with a touchdown (6 points)
    if (lastplay <= 6)
    {
        findscores(score - 6, 6, td2pt, td1pt, td + 1, fg, safety);
    }

    // Try scoring with a field goal (3 points)
    if (lastplay <= 3)
    {
        findscores(score - 3, 3, td2pt, td1pt, td, fg + 1, safety);
    }

    // Try scoring with a safety (2 points)
    if (lastplay <= 2)
    {
        findscores(score - 2, 2, td2pt, td1pt, td, fg, safety + 1);
    }
}
int main()
{
    int score;
    while (1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // If the input is 0 or 1, stop the loop.
        if (score <= 1)
        {
            break;
        }

        // Output possible combinations of scoring plays for the given score.
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        findscores(score, 0, 0, 0, 0, 0, 0);
        printf("\n");
    }

    return 0;
}
