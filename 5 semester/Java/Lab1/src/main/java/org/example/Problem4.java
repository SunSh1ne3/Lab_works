package org.example;

import java.util.Arrays;

public class Problem4 {
    public static boolean isGeometricProgression(String numbers) {
        int Arr[]=new int[numbers.split(",").length];
        int i=0;
        for(String tmp:numbers.split(",")) {
            Arr[i] = Integer.parseInt(tmp);
            i++;
        }
        Arrays.sort(Arr);

        int d=Arr[1]/Arr[0];
        for(int j=2;j<Arr.length;j++)
        {
            if(Arr[j]/d!=Arr[j-1])
                return false;
        }
        return true;
    }
}
