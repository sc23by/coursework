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