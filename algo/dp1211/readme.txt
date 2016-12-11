Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
     You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character

Firstly， recursive style
With plain language, word A is able to be transformed to be word B, by the method including
1.  add word B's relative first character to its head.
2. delete word A's current head character to see whether the remaining section fits the need.
3. replace the word A's current head character with one of current word B's, and so on so forth

distance(str1, start1, len1, str2, start2, len2)
{
     int ret = 0；

   if ((start1 < len1) && (start2 < len2) (str1[start1] == str2[start2]))
     {
          ret = (str1, start1+1，len1-1, str2, start2 +1,len2-1);
     }
     else
      {
          if (len1 >0 && start1 < len1)
          //delete str1 's first character to try to assimilate both of the head
               ret1 =  distance(str1, start1+1,len1-1, str2, start2, len2)

          //add str2 's first character to the start of the str1 to assimilate both of the head
         if (len2 > 0 && start2 < len2)
               ret2 =  distance(str1, start1,len+1, str2, start2+1,len2)

          //replace the str1's first character with the str2's first character
          if (len1 > 0 && len2 > 0&&start1 < len1 && start2 < len2)
         ret3 = (str1, start1+1, str2, start2 +1);

          ret = min(ret1, ret2, ret3) + 1;
       }
       return ret;
}

     Although it is way easy to assign everything to the machine to complete the recursive task which is time consuming, it
is imperative to restructure our computing model in the attempt to enhance the performance, by the method of DP.
     It is plain to see that a lot of repeated calculation would occur with the recursive calculation. The point of DP lies in the exemption from these calculation redundancy.
     For DP method, on the first hand, one structural data shall be designed to store the temporary executing instance, and most importantly the relation of each instance between each iteration.
     From recursion, it can be seen that the repeated calculation has close bearing with things such as length, starting offset and etc, which is helpful in the attempt to put forward one structural data for temporary storage. Namely, we denote DP[I][J] to be
the editing distance between the substring s1[1,I] and s2[1,J].

     The connection between these calculation instances are, to name a few:
      DP[i][j] VS DP[i-1][j] ?     DP[i][j] = DP[i-1][j] + 1
      DP[i][j] VS DP[i][j-1] ?     DP[i][j] = DP[i][j-1] + 1
      DP[i][j] VS DP[i-1][j-1] ?  DP[i][j] = DP[i-1][j-1] + 1 (replacement of the head character)
                                                            or = DP[i-1][j-1] (boundary character totally the same)

       Thus the dp solution comes this way,

          i -> word A length
        DP[i][0] = i;
          j -> word B length
        DP[0][j] = j;