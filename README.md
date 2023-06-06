# Exact Pattern Matching Algorithms and Analysis

## Author: Pallavi Garg
pallavg1@uci.edu

## Algorithms
1. Brute force
2. Knuth-Morris-Pratt (KMP)
3. Boyer-Moore-Horspool (BMH)
4. Bitap
5. Rabin Karp

## Test Setup
1. Random Strings Testing
2. English Strings and Words Testing

## To run the algorithms
```
./project "Text" "Pattern" "algo"
```
## Observation

1. Random strings: KMP algorithm performs the best

![random strings test](/outputs/random.png)

2. English Strings and Words: KMP algorithm performs the best

![english strings test](/outputs/english.png)

## Conclusion
As per the observations, in both test settings KMP performs the best in both these test setups.
The BMH algorithm performed poorly in this setup.
The reason for this observation is that:
1. The KMP uses the information about the previous comparisons which makes it fast for
these scenarios. Because of the large degree of similarity among portions of pattern and
text in English words setup, the BMH algorithm makes a lot of comparisons before it is
able to find a match.
2. In both the test setups, text contains a large number of repeating characters and BMH
algorithm relies on the “bad character shift” to determine how far to move the pattern
when mismatch occurs. Which makes it shift the pattern by a small amount only,
resulting in greater number of comparisons. On the other hand, the KMP algorithm uses
the previous match information, which makes it much faster.

In general, it is noticeable from both the graphs, that brute force algorithm performance is better
than both Rabin Karp and BMH algorithms. This shows that depending on the problem, brute
force algorithm might be a better choice.

Overall, the performance of these algorithms depends on the characteristics of the specific
problem being solved. It is important to consider the properties of the text and pattern when
selecting an algorithm for string matching.
