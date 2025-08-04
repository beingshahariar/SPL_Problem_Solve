#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Player{
    char player_name[50];
    int player_number;
    char player_position[4];
    int goals_scored;
    int goals_conceded;
    int number_of_minutes_played;
}Player;

typedef struct Team {
    char team_name[10];
    Player players[20];
    int num_players;
}Team;

Team teams[10];
int num_teams = 0;

void menu() {
    printf("Click a number\n");
    printf("1.Add Player to Team\n");
    printf("2.Update Team\n");
    printf("3.Display Player Information\n");
    printf("4.Display Team Information\n");
    printf("5.Save Teams to File\n");
    printf("6.Load Teams from File\n");
    printf("7.Exit\n");
}

void addPlayerToTeam() {
    if (num_teams >= 10 || teams[num_teams].num_players >= 20) {
        printf("Couldn't Add\n");
    }
    else {
        printf("Enter team name: \n");
        scanf("%s", teams[num_teams].team_name);

        Player new_player;
        printf("Enter player name: \n");
        scanf("%s", new_player.player_name);
        printf("Enter player number: \n");
        scanf("%d", &new_player.player_number);
        printf("Enter player position : \n");
        scanf("%s", new_player.player_position);
        if(strcmp(new_player.player_position, "DEF") == 0) {
            printf("Enter goals scored by the player: \n");
            scanf("%d", &new_player.goals_scored);
        }
        if(strcmp(new_player.player_position, "MID") == 0 || strcmp(new_player.player_position, "FWD") == 0) {
            printf("Enter goals scored by the player: \n");
            scanf("%d", &new_player.goals_scored);
        }
        printf("Enter number of minutes played by the player: \n");
        scanf("%d", &new_player.number_of_minutes_played);
        teams[num_teams].players[teams[num_teams].num_players++] = new_player;
        num_teams++;
    }
}

void updateTeam() {
    char team_name[50];
    printf("Enter team name: ");
    gets(team_name);

    int i;
    for (i = 0; i < num_teams; i++) {
        if (strcmp(teams[i].team_name, team_name) == 0) {
            int j;
            for (j = 0; j < teams[i].num_players; j++) {
                if (strcmp(teams[i].players[j].player_position, "MID") == 0 ||
                    strcmp(teams[i].players[j].player_position, "FWD") == 0) {
                    printf("Enter goals scored by player %s: ", teams[i].players[j].player_name);
                    scanf("%d", &teams[i].players[j].goals_scored);
                } else if (strcmp(teams[i].players[j].player_position, "DEF") == 0) {
                    printf("Enter goals conceded by player %s: ", teams[i].players[j].player_name);
                    scanf("%d", &teams[i].players[j].goals_conceded);
                }
            }
        }
    }
}


void displayPlayer() {
    char player_name[50];
    printf("Enter player name: ");
    scanf("%s", player_name);

    int i, j;
    for (i = 0; i < num_teams; i++) {
        for (j = 0; j < teams[i].num_players; j++) {
            if (strcmp(teams[i].players[j].player_name, player_name) == 0) {
                printf("Player Name: %s\n", teams[i].players[j].player_name);
                printf("Player Number: %d\n", teams[i].players[j].player_number);
                printf("Player Position: %s\n", teams[i].players[j].player_position);
                if(strcmp(teams[i].players[j].player_position, "DEF") == 0) {
                     printf("Goals Conceded: %d\n", teams[i].players[j].goals_conceded);
                }
                if(strcmp(teams[i].players[j].player_position, "MID") == 0 || strcmp(teams[i].players[j].player_position, "FWD") == 0) {
                    printf("Goals Scored: %d\n", teams[i].players[j].goals_scored);
                }
                printf("Number of Minutes Played: %d\n", teams[i].players[j].number_of_minutes_played);
            }
        }
    }
}

void displayTeam() {
    char team_name[50];
    printf("Enter team name: ");
    scanf("%s", team_name);

    int i;
    for (i = 0; i < num_teams; i++) {
        if (strcmp(teams[i].team_name, team_name) == 0) {
            printf("Team Name: %s\n", teams[i].team_name);
            printf("Number of Players: %d\n", teams[i].num_players);
            printf("Players:\n");
            int j;
            for (j = 0; j < teams[i].num_players; j++) {
                printf("Player Name: %s, Player Number: %d\n", teams[i].players[j].player_name, teams[i].players[j].player_number);
            }
            return;
        }
    }
    printf("Team not found.\n");
}

void saveTeamsToFile() {
    FILE *file = fopen("football_database.txt", "w");

    int i, j;
    for (i = 0; i < num_teams; i++) {
        fprintf(file, "Team Name: %s\n", teams[i].team_name);
        fprintf(file, "Number of Players: %d\n", teams[i].num_players);
        for (j = 0; j < teams[i].num_players; j++) {
            fprintf(file, "Player Name: %s\n", teams[i].players[j].player_name);
            fprintf(file, "Player Number: %d\n", teams[i].players[j].player_number);
            fprintf(file, "Player Position: %s\n", teams[i].players[j].player_position);

            if(strcmp(teams[i].players[j].player_position, "MID") == 0 || strcmp(teams[i].players[j].player_position, "FWD") == 0) {
                    fprintf(file,"Goals Scored: %d\n", teams[i].players[j].goals_scored);
            }
            if(strcmp(teams[i].players[j].player_position, "DEF") == 0){
                fprintf(file, "Goals Conceded: %d\n", teams[i].players[j].goals_conceded);
            }
            fprintf(file, "Number of Minutes Played: %d\n", teams[i].players[j].number_of_minutes_played);
        }
    }

    fclose(file);
    printf("Teams data saved to file successfully.\n");
}

void loadTeamsFromFile() {
    FILE *file = fopen("football_database.txt", "r");
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
}

int main() {
    int choice;

    do{
    printf("Click a number\n");
    printf("1.Add Player to Team\n");
    printf("2.Update Team\n");
    printf("3.Display Player Information\n");
    printf("4.Display Team Information\n");
    printf("5.Save Teams to File\n");
    printf("6.Load Teams from File\n");
    printf("7.Exit\n");
    scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPlayerToTeam();
                break;
            case 2:
                updateTeam();
                break;
            case 3:
                displayPlayer();
                break;
            case 4:
                displayTeam();
                break;
            case 5:
                saveTeamsToFile();
                break;
            case 6:
                loadTeamsFromFile();
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 7);

    return 0;
}
