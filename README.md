# coursework
                strcpy(minstepsrecord, record);
            printf("Fewest Steps: %d\n",minsteps);
            printf("Fewest Steps: %s", minstepsrecord);

                        // Check if the last period is the longest
            if (currentsteps > currentlongeststeps) 
            {
                currentlongeststeps = currentsteps;

                strcpy(enddate, prevenddate);  // Use the previous date
                strcpy(endtime, prevendtime);

            }


                            // Store the current date and time for the next iteration
                strcpy(prevenddate, date);
                strcpy(prevendtime, time);


            if(strchr(steps, '0') != NULL && strchr(steps, '1') != NULL && strchr(steps, '2') != NULL && strchr(steps, '3') != NULL && strchr(steps, '4') != NULL && strchr(steps, '5') != NULL && strchr(steps, '6') != NULL && strchr(steps, '7') != NULL && strchr(steps, '8') != NULL && strchr(steps, '9') != NULL)
        {
            printf("Error: invalid file\n");
            return 1;
        }