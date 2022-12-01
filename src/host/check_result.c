//
// Created by 23503 on 2022/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "typedefs.h"


void check_results(LabelType* result, const LabelType* expected, int cnt)
{
    int correct_cnt = 0;

    FILE *ofile=NULL;
    ofile=fopen("outputs.txt","w");
    if (ofile!=NULL)
    {
        for (int i = 0; i < cnt; i ++ )
        {
            if (result[i] != expected[i])
//                ofile << "Test " << i << ": expected = " << int(expected[i]) << ", result = " << int(result[i]) << std::endl;
                fprintf(ofile,"Test %d: expected = %d, result = %d \n",i,(int)expected[i],(int)result[i]);
            else
            correct_cnt ++;
        }

//        ofile << "\n\t " << correct_cnt << " / " << cnt << " correct!" << std::endl;
        fprintf(ofile,"\n\t %d / %d correct!\n", correct_cnt,cnt);
//        ofile.close();
        fclose(ofile);
    }
    else
    {
        printf("Failed to create output file!\n");
    }


}

