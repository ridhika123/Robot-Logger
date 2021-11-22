#include <stdio.h>
#include <stdlib.h>
#include <MyroC.h>
#include <unistd.h>
#include <string.h>

/******************** PRE AND POST CONDITIONS ********************/

/*** Case 1 ***/
/* Procedure to scan and return a decimal number. */
/* Pre-conditions: user enters a decimal number between 0 and 1.
 * Post-conditions: returns a double between 0 and 1.
 */
double reading_speed_for_moving_forward (void);

/* Procedure to make robot move forward for a specified speed. */
/* Pre-conditions: speed is a double between 0 and 1 inclusive.
 * Post-conditions: robot moves forward.
 */
void r_moving_forward_robot (double speed);

/*** Case 2 ***/
/* Procedure to scan and return positve integer. */
/* Pre-conditions: user enters a non-zero positive number.
 * Post-conditions: returns the integer that the user entered.
 */
int reading_number_of_times_dance_performed (void);

/* Procedure to make robot perform a dance routine given number of times. */
/* Pre-conditions: num_of_times_performed is a non-zero positive integer.
 * Post-conditions: robot performs dance routine num_of_times_performed number of times.
 */
void r_dancing_robot (int num_of_times_performed);

/*** Case 3 ***/
/* Procedure to scan and return 1 number between 0 and 3. */
/* Pre-conditions: user enters a number between 0 and 3.
 * Post-conditions: returns a double.
 */
double reading_time_of_beeps (void);

/* Procedure to make robot beep for a given number of times from 0 to 3 seconds. */
/* Pre-conditions: times_for_beeps[] is an array of 3 doubles for the times for beeps.
 * Post-conditions: robot beeps 3 times at 3 different frequencies.
 */
void r_beeping_robot (double time_for_beep_1, double time_for_beep_2, double time_for_beep_3);

/*** Case 4 ***/
/* Procedure to make robot turn left as a non-blocking procedure. */
/* Pre-conditions: none.
 * Post-conditions: robot moves left as a non-blocking procedure.
 */
void r_turning_left (void);

/*** Case 5 ***/
/* Procedure to scan and return a number between 0 and 1. */
/* Pre-conditions: user enters a double between 0 and 1.
 * Post-conditions: returns the number that the user entered.
 */
double reading_speed_for_moving_backwards (void);

/* Procedure to make robot turn left as a non-blocking procedure. */
/* Pre-conditions: speed_for_backward is a double between 0 and 1.
 * Post-conditions: robot moves backwards as a non-blocking procedure.
 */
void r_moving_backwards_robot (double speed_for_backward);

/*** Case 6 ***/
/* Procedure to scan and return a non-zero positive integer. */
/* Pre-conditions: user enters a non-zero positive integer.
 * Post-conditions: returns the number that the user entered.
 */
int 
reading_spins_for_spinning_robot (void);

/* Procedure to make robot spin clockwise and anti-clockwise alternatingly for a given number of times. */
/* Pre-conditions: number_of_spins is an non-zero positive integer.
 * Post-conditions: robot spins clockwise and anti-clockwise alternatingly.
 */
void r_spinning_robot (int number_of_spins);

/*** Case 7 ***/
/* Procedure to scan and return an integer. */
/* Pre-conditions: user enters an integer from 500 or 1500.
 * Post-conditions: returns one of the two integer's.
 */
int reading_frequencies_for_beep (void);


/* Procedure to make robot dance with beeps and movements. */
/* Pre-conditions: frequencies_for_beeps[] is an array of 4 integers.
 * Post-conditions: robot dances with beeps and movements.
 */
void r_dancing_with_beeps_robot (int frequency_for_beep_1, int frequency_for_beep_2, int frequency_for_beep_3, int frequency_for_beep_4);

/*** Case 8 ***/
/* Procedure to scan and return a non-zero positive integer. */
/* Pre-conditions: user enters 1 non-zero positive integer.
 * Post-conditions: returns the integer the user intered.
 */
int reading_number_of_pictures (void);

/* Procedure to make robot click and display picture given number_of_pictures of times. */
/* Pre-conditions: number_of_pictures is a non-zero positive integer.
 * Post-conditions: robot clicks and displays pictures after taking right turns.
 */
void r_clicking_pictures_robot (int number_of_pictures);

/*** Case 9 ***/
/* Procedure to scan and return a non-zero positive integer. */
/* Pre-conditions: user enters 1 non-zero positive integer.
 * Post-conditions: returns the integer the user intered.
 */
int reading_number_of_readings (void);

/* Procedure to make robot read light and display message about quantity. */
/* Pre-conditions: number_of_readings is a non-zero positive integer.
 * Post-conditions: robot clicks and displays pictures after taking right turns number_of_readings times.
 */
void displays_light_conditions_robot (int number_of_readings);

/***************************** MACRO VARIABLES *****************************/

#define TIME_FOR_MOVE_FORWARD 4
#define TIME_FOR_DANCE 1
#define SPEED_BACK_FORW_FOR_DANCE 0.5
#define SPEED_LEFT_RIGHT_DANCE 0.2
#define SPEED_RIGHT_LEFT_DANCE 0.8
#define FREQUENCY_FOR_BEEP_1 500
#define FREQUENCY_FOR_BEEP_2 1000
#define FREQUENCY_FOR_BEEP_3 1500
#define SPEED_FOR_LEFT 0.5
#define TIME_FOR_LEFT -10
#define SPEED_FOR_BACK -5
#define MOTOR_SPEED_1 0
#define MOTOR_SPEED_2 0.9
#define SLEEP_TIME 1
#define TIME_DANCE_MOVES -1
#define SPEED_DANCE_MOVES 0.5
#define TIME_DANCE_BEEPS 1
#define SPEED_RIGHT 0.2
#define TIME_RIGHT -0.5
#define TIME_DISPLAY -10
#define SPEED_RIGHT_LIGHT 0.8
#define TIME_RIGHT_LIGHT 1
#define MAXSTR 15
#define MAXINPUT "%15s"
#define SPEED_FOR_TURN 1
#define TIME_FOR_TURN 3
#define WINDOW_NAME 30
/***************************** FUNCTIONS *****************************/

/* Case 1: Function for moving forward which is blocking and takes parameters. */

double 
reading_speed_for_moving_forward (void)
{
  double speed;
  printf("Enter a number between 0 and 1 for speed to make robot move forward: ");
  scanf("%lf", &speed); //scanning double
  return speed;
} //reading_speed_for_moving_forward

void 
r_moving_forward_robot (double speed)
{
  if (speed > 1 || speed < 0)
    printf("Invalid input, number has to be between 0 and 1.\n");
  else
    {printf("Robot is now executing case 1:\n");
      printf("Robot is now moving forward!!\n");
      rForward (speed, TIME_FOR_MOVE_FORWARD);} //moves robot forward
} //r_moving_forward_robot

/* Case 2: Function to beep 3 times at given frequencies (takes parameters),
   and the function is blocking. */

double reading_time_of_beeps (void)
{
  double time_for_beep;

  printf("Enter a number between 0 and 3 for time of beeps: ");
  scanf("%lf", &time_for_beep); //scanning double
  return time_for_beep;
} //reading_time_for_beeps

void 
r_beeping_robot (double time_for_beep_1, double time_for_beep_2, double time_for_beep_3)
{
  if ((time_for_beep_1 > 3 || time_for_beep_1 < 0) ||
      (time_for_beep_1 > 3 || time_for_beep_1 < 0) ||
      (time_for_beep_1 > 3 || time_for_beep_1 < 0))
    printf("Invalid input(s), number has to be between 0 and 3.\n");
  else
    {
      printf("Robot is now executing case 2:\n");
  
      printf("Robot is beeping once\n");
      rBeep(time_for_beep_1, FREQUENCY_FOR_BEEP_1);//makes robot beep
      printf("And now another time\n");
      rBeep(time_for_beep_2, FREQUENCY_FOR_BEEP_2);//makes robot beep
      printf("And one last time!!\n");
      rBeep(time_for_beep_3, FREQUENCY_FOR_BEEP_3);//makes robot beep
    }
} //r_beeping_robot


/* Case 3: Function for making the robot dance a given number of times (takes parameters),
   and the function is blocking. */

int 
reading_number_of_times_dance_performed (void)
{
  int num_of_times_performed;
  printf("Enter a nonzero positive integer for making robot dance a number of times: ");
  scanf("%d", &num_of_times_performed); //scanning integer
  return num_of_times_performed;
} //reading_number_of_times_dance_performed

void 
r_dancing_robot (int num_of_times_performed)
{
  if (num_of_times_performed <= 0)
    printf("Invalid input, number has to be nonzero and positive.\n");
  else
    {
      printf("Robot is now executing case 3:\n");
      for (int i = 0; i < num_of_times_performed;i++)
        {
          printf("Robot is spinninggg\n");
          rMotors (SPEED_LEFT_RIGHT_DANCE, SPEED_RIGHT_LEFT_DANCE); //moves robot around
          sleep(SLEEP_TIME);

          printf("And the other way!!\n");
          rMotors (SPEED_RIGHT_LEFT_DANCE, SPEED_LEFT_RIGHT_DANCE); //moves robot in the opposite direction
          sleep(SLEEP_TIME);

          printf("Robot is moving backwards,\n");
          rBackward(SPEED_BACK_FORW_FOR_DANCE, TIME_FOR_DANCE); //moves robot back

          printf("and now forwards!!\n");
          rForward (SPEED_BACK_FORW_FOR_DANCE, TIME_FOR_DANCE); //moves robot forward
        }
    }
} //r_dancing_robot

/* Case 4: Function to make robot turn left as non-blocking action. */

void 
r_turning_left (void)
{
  printf("Robot is now executing case 4:\n");
  printf("Robot turning left!!\n");
  rTurnLeft(SPEED_FOR_LEFT, TIME_FOR_LEFT ); //moves robot to left
} //r_turning_left

/* Case 5: Function to make robot move backward at a given speed (takes parameters),
   and the function is non-blocking. */

double reading_speed_for_moving_backwards (void)
{
  double speed_for_backward;
  printf("Enter a number between 0 and 1 for speed to make robot move backwards: ");
  scanf("%lf", &speed_for_backward);  //scanning double
  return speed_for_backward;
} //reading_speed_for_moving_backwards

void 
r_moving_backwards_robot (double speed_for_backward)
{
  if (speed_for_backward > 1 || speed_for_backward < 0)
    printf("Invalid input, number has to be between 0 and 1.\n");
  else
    {
      printf("Robot is now executing case 5:\n");
      printf("Robot is moving backwards!!\n");
      rBackward(speed_for_backward, SPEED_FOR_BACK);//moves robot backwards
    }
} //r_moving_backwards_robot

/* Case 6: Function to make robot move clockwise and anticlockwise for a given number of time (takes parameters),
   and the function is blocking. */

int 
reading_spins_for_spinning_robot (void)
{
  int number_of_spins;
  printf("Enter a non-zero positive number to make robot spin a numebr of times: ");
  scanf("%d", &number_of_spins);//scanning integer
  return number_of_spins;
} //reading_spins_for_spinning_robot

void 
r_spinning_robot (int number_of_spins)
{
  if (number_of_spins <= 0)
    printf("Invalid input, number has to be nonzero and positive.\n");
  else
    {
      printf("Robot is now executing case 6:\n");
      for (int i = 0; i < number_of_spins; i++)
        {
          if (i % 2 == 0) //if i is even, sping in one direction
            {
              printf("Robot is now spinning anti-clockwise!!\n");
              rTurnLeft (SPEED_FOR_TURN, TIME_FOR_TURN);
            }
          else //if i is odd, sping in another direction
            {
              printf("And now clockwise!!\n");
              rTurnRight(SPEED_FOR_TURN, TIME_FOR_TURN);
            }
        }
    }
} //r_spinning_robot

  /* Case 7: Function to make robot beep while turning in four directions for a given frequency (takes parameters),
     and the action is blocking. */

int reading_frequencies_for_beep (void)
{
  int frequency_for_beep;

  printf("Enter one of the following numbers: 500 and 1500 as frequency for beep by robot: ");
  scanf("%d", &frequency_for_beep); //scanning integer
  return frequency_for_beep;
} //reading_frequencies_for_beep

void r_dancing_with_beeps_robot (int frequency_for_beep_1, int frequency_for_beep_2, int frequency_for_beep_3, int frequency_for_beep_4)
{
  if ( ((frequency_for_beep_1 == 500) || (frequency_for_beep_1 == 1500)) &&
       ((frequency_for_beep_2 == 500) || (frequency_for_beep_2 == 1500)) &&
       ((frequency_for_beep_3 == 500) || (frequency_for_beep_3 == 1500)) &&
       ((frequency_for_beep_4 == 500) || (frequency_for_beep_4 == 1500)))
  
    {
      printf("Robot is now executing case 7:\n");
    
      printf("Robot is turning left and beeping\n");
      rTurnLeft(SPEED_DANCE_MOVES, TIME_DANCE_MOVES); 
      rBeep(TIME_DANCE_BEEPS, frequency_for_beep_1); //making robot turn left and beep
    
      printf("and now moving forward while beeping\n");
      rForward(SPEED_DANCE_MOVES, TIME_DANCE_MOVES);
      rBeep(TIME_DANCE_BEEPS,frequency_for_beep_2); //making robot move forward and beep 
     
      printf("and now moving right while beeping\n");
      rTurnRight(SPEED_DANCE_MOVES, TIME_DANCE_MOVES); 
      rBeep(TIME_DANCE_BEEPS,frequency_for_beep_3); //making robot turn right and beep
      
      printf("and finally moving backwards while beeping!!\n");
      rBackward(SPEED_DANCE_MOVES, TIME_DANCE_MOVES);
      rBeep(TIME_DANCE_BEEPS,frequency_for_beep_4); //making robot move back and beep
    }
  else
    {
      printf("Invalid input, number has to be 500 or 1500!!! Go drunk home you are! .\n");
    }
} //r_dancing_with_beeps_robot

  /* Case 8: Function to make robot click and display given number of pictures (takes parameters),
     and function is non-blocking. */

int 
reading_number_of_pictures (void)
{
  int number_of_pictures;
  printf("How many pictures do you want to take? Enter a non-zero positive number: ");
  scanf("%d", &number_of_pictures); //scanning integer

  return number_of_pictures;
} //reading_number_of_pictures

void r_clicking_pictures_robot (int number_of_pictures)
{
  if (number_of_pictures <= 0)
    printf("Invalid input, number has to be nonzero and positive.\n");
  else
    {
      printf("Robot is now executing case 8:\n");
      Picture pics[number_of_pictures];
      char window_name[WINDOW_NAME] =
        "Some random pictures for you!"; 
      for (int i = 0; i < number_of_pictures ; i++)
        {
          pics[i] = rTakePicture();
          printf("Now turning right!\n");
          rTurnRight (SPEED_RIGHT, TIME_RIGHT); //making robot turn right
          printf("And displaying pictures.\n");
          rDisplayPicture (&pics[i], TIME_DISPLAY, window_name); //displaying pictures 
        }
    }
} //r_clicking_pictures_robot

/* Case 9: Function to take certain number of readings of lights (takes parameters),
   and function is blocking. */

int reading_number_of_readings (void)
{
  int number_of_readings;
  printf("How many light readings do you want to take? Enter a non-zero positive number: ");
  scanf("%d", &number_of_readings); //scanning integer
  return number_of_readings;
} //reading_number_of_readings

void r_displays_light_conditions_robot (int number_of_readings)
{
  if (number_of_readings <= 0)
    printf("Invalid input, number has to be nonzero and positive.\n");
  else
    {
      printf("Robot is now executing case 9:\n");
      for (int i = 0; i < number_of_readings; i++)
        {
          int light_reading_1 = rGetLightTxt ("left", 1); //getting 3 readings of lights
          int light_reading_2 = rGetLightTxt ("left", 1);
          int light_reading_3 = rGetLightTxt ("left", 1);
          int light_reading_avg = (light_reading_1 + light_reading_2 + light_reading_3)/3; //averaging the 3 readings 
          printf("The amount of light as detected by the left sensor is: %d.\n", light_reading_avg);
          rTurnRight(SPEED_RIGHT_LIGHT , TIME_RIGHT_LIGHT); //making robot turn right
        }
    }
} //r_displays_light_conditions_robot


  /* Main function. */

/* Procedure to display the 10 possible commands and execute the commands once the user provides an input. */
/* Note: this was the main function from Project 3. */
void
list_of_actions (FILE * file_for_input, FILE * file_for_output) 
{
  int count = 0; //initializing variable to maintain count of actions
  char input[MAXSTR+1];
  while (1)
    {
      fprintf(file_for_output, "Menu Options:\n");
      fprintf(file_for_output, "forward - moves forward for given speed.\n");
      fprintf(file_for_output, "beep - beeps 3 times at times given by user.\n");
      fprintf(file_for_putput, "dance - performs dance specified number of times.\n");
      fprintf(file_for_output, "left - turns left as a non-blocking action.\n");
      fprintf(file_for_output, "back - moves backwards as a non-blocking action.\n");  
      fprintf(file_for_output, "spin - spins clockwise and anti-clockwise alternatingly, given number of times.\n");
      fprintf(file_for_output, "danceNbeep - performs dance with beeps given frequencies by user.\n");
      fprintf(file_for_output, "pics - clicks and displays specified number of pictures.\n");
      fprintf(file_for_output,  "brightness? - displays light conditions on left side of robot.\n");
      fprintf(file_for_output, "QUIT - Quit\n");
 
      fprintf (file_for_output, "Enter option: ");
      fscanf(file_for_input, MAXINPUT, input); //scanning integer for execution of 1 of 10 cases
        
      if ((strcmp (input, "forward")) == 0) 
        {
          r_moving_forward_robot (reading_speed_for_moving_forward());
          ++count;
        }
      else if((strcmp (input, "beep")) == 0) 
        {
          r_beeping_robot(reading_time_of_beeps(),reading_time_of_beeps(),reading_time_of_beeps());
          ++count;
        }
      else if ((strcmp (input, "dance")) == 0) 
        {
          r_dancing_robot(reading_number_of_times_dance_performed());
          ++count;
        }
      else if ((strcmp (input, "left")) == 0) 
        {
          r_turning_left(); 
          ++count;
        }
      else if ((strcmp (input, "back")) == 0)
        {
          r_moving_backwards_robot (reading_speed_for_moving_backwards ());
          ++count;
        }
        
      else if ((strcmp (input, "spin")) == 0)
        {
          r_spinning_robot(reading_spins_for_spinning_robot());
          ++count;
        }
      else if   ((strcmp (input, "danceNbeep")) == 0)
        {
          r_dancing_with_beeps_robot (reading_frequencies_for_beep(), reading_frequencies_for_beep(),
                                      reading_frequencies_for_beep(), reading_frequencies_for_beep());
          ++count;
        }
      else if ((strcmp (input, "pics")) == 0)
        {
          r_clicking_pictures_robot (reading_number_of_pictures());
          ++count;
        }
      else if ((strcmp (input, "brightness?")) == 0)
        {
          r_displays_light_conditions_robot (reading_number_of_readings ());
          ++count;
        }
      else if ((strcmp (input, "QUIT")) == 0)
        {
          fprintf(file_for_output, "The total number of actions performed by the robot is: %d.\n", count);
          fprintf(file_for_output, "The program is now terminating.\n");
          return;
        }
      else
        {
          fprintf(file_for_output, "Not a valid input, please try again.\n");
          continue;
        } 
    } //while(1)
} //list_of_actions


/* void */
/* checking_files (int flag_w, int flag_r, int file_w, int file_r) */
/* { */
/*   if (flag_w) */
/*     { */
/*       if (flag_r) */
/*         {} */
/*           else if (file_r) */
/*             {} */
/*           else */
/*             stdin */
/*     } */
/*   if (file_w) */
/*     {if (flag_r) */
/*         {} */
/*           else if (file_r) */
/*             {} */
/*           else */
/*             stdin */
/*     } */
/* } */

/* int */
/* checks_flag (char flag) */
/* { */
/*   switch (flag) */
/*   case 'w': return 1; */
/*   case 'r': return 1; */
/*     /\* case 'h':  *\/ */
/*     /\*   break; *\/ */
/* } */


char *
check_file_name(int i, char * argv[])
{
  if (argv[i+1] == NULL)
    {
      printf("What file should the function use?");
      return argv[0]; //CHECK THISSSS
    }
  else
    return argv[i+1];
}


int
main (int argc, char * argv[])
{
  rConnect ("/dev/rfcomm0");
  
  FILE * file_for_input = stdin;
  FILE * file_for_output = stdout;
  
  for (int i = 1; i < argc; i++)
    {
      printf("in the loop\n");
      
      if((argv[i][0] == '-') && (argv[i][1] == 'r'))
        {
          printf("in -r\n");
          file_for_input = fopen(check_file_name(i, argv), "r");
          if (file_for_input == NULL){
            perror("Cannot open file");
            return EXIT_FAILURE;
          }
        }

      else if((argv[i][0] == '-') && (argv[i][1] == 'w'))
        {
          printf("in -w\n");
          file_for_output = fopen(check_file_name(i, argv), "w");
          if (file_for_output == NULL){
            perror("Cannot write in fileopen");
            return EXIT_FAILURE;
          }
        }

      else if (strcmp(argv[i], "r"))
        {
          file_for_input = fopen(argv[i], "r");
          if (file_for_input == NULL){
            perror("Cannot open file");
            return EXIT_FAILURE;
          }
        }

      else if (strcmp(argv[i], "w"))
        {
          file_for_output = fopen(argv[i], "w");
          if (file_for_output == NULL){
            perror("Cannot write in file");
            return EXIT_FAILURE;
          }
        }     
    }
  
  list_of_actions(file_for_input, file_for_output);
  
  rDisconnect();
  return 0;
}
  
  /* if (argc == 1) */
  /*   { */
  /*     char * command_for_robot; */
  /*     while (!feof(stdin)) */
  /*       { */
  /*         fscanf(stdin, "%s", &command_for_robot); */
  /*         action_by_robot(command_for_robot); */
  /*         fprintf(stdout, "%s", command_for_robot); */
  /*       } */
  /*   } */

  /// -h!!!!!!!!
  
  /* int flag_w = 0; */
  /* int flag_r = 0; */
  /* int file_w = 0; */
  /* int file_r = 0; */

  /* for (int i = 1; i < argc; i++) */
  /*   { */
  /*     if((argv[i][0] == '-') && isalpha(argv[i][1])) */
  /*       { */
  /*         flag_w = check_flag(argv[i][1]); */
  /*         flag_r = check_flag(argv[i][1]); */
  /*       } */

  /*     else if(argv[i] == "w") */
  /*       { */
  /*         file_w = 1; */
  /*       } */
  /*     else if(argv[i] == "r") */
  /*       { */
  /*         file_r = 1; */
  /*       }     */
  /*   } */

  /* checking_files (flag_w, flag_r, file_w, file_r); */

