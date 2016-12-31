By the way, Sherry, I have a crush on her when we had dinner together, and i think she is the lady for my life.

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Recursive way:

russian_doll()
{
     for each index -> entries number
     {
          return max exec_doll(entries,index)
     }
}

exec_doll(entry, start)
{
     for each index
     {
          if qualified(entry,index)
          {
               register(index);
               tmp = exec(entry, index);
               if tmp > max
                    max = tmp;
               unregister(index);
          }
     }
     return max + 1;
}

DP way:
Firstly, what dp means is that dp[n] stores the sum of the sub envelopes that are contained in this largest envelope. Thus,
     dp[n] =

namely there is three boxes, {b0, b1, b2}, and in which set b0 > b1, b0 > b2, and b1 is incompatible with b2, and how we adopt DP algorithm on these three?

We have to sort these nodes on the basis of each height and width first， and next to cope with the problem in the method of Largest Increasing Subsequence.

From b0 on, the strategy is to seek one relation with unknown node, say between b0 and b1, if b0 is comparable with b1 thus both nodes are of the same set, and here goes the DP seudo code

sort the sequence of envelope;
for each entry i in list
{
     for each another entry j to entry i in list
     {
          if entry j  < entry i
          {
                   dp[i] = max(dp[i], dp[j] + 1);
          }
     }
}