# Possible Paths
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a tree with N nodes and (N-1) edges such that&nbsp;each edge has some weight. You are given Q queries.&nbsp;Each query contains&nbsp;a number X.&nbsp;Find the number of paths in which the edge that has the maximum weight is less than or equals to X. </span></p>

<p><span style="font-size:18px"><strong>Note:</strong> Path from A to B and B to A are considered to be the same.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 7
</span><span style="font-size:18px">Tree = 
&nbsp;&nbsp; &nbsp; &nbsp;&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;<strong>1</strong>
&nbsp;&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;<sup>3</sup> <strong>/</strong>
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;<strong>/</strong>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; <strong>&nbsp;2</strong>
<strong>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; &nbsp;/&nbsp;\</strong>
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; <sup>1</sup> <strong>/ &nbsp; \</strong><sup> 9</sup>
<strong>&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;/ &nbsp; &nbsp; \</strong>
&nbsp;&nbsp; &nbsp; &nbsp; <strong>3</strong> &nbsp; &nbsp; &nbsp; <strong>4</strong>
<strong>&nbsp; &nbsp; &nbsp; / \ &nbsp;&nbsp; &nbsp;</strong>
&nbsp;&nbsp; <sup>7</sup> <strong>/ &nbsp; \ </strong><sup>8</sup>
&nbsp;&nbsp; &nbsp;<strong>/ &nbsp; &nbsp; \</strong>
&nbsp; &nbsp;<strong>6</strong> &nbsp; &nbsp; &nbsp; <strong>5</strong>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <strong>/&nbsp;&nbsp; &nbsp;</strong>
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; <sup>4</sup> <strong>/</strong>
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;<strong>/</strong>
&nbsp;&nbsp; <strong>&nbsp; &nbsp; 7</strong>
list of edges {start,end,weight}= 
{{1, 2, 3}, {2, 3, 1}, {2, 4, 9},
{3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
</span><span style="font-size:18px">Q = 3
queries[] = {1, 3, 5}
<strong>Output:</strong> 1 3 4
<strong>Explanation:</strong> </span>
<span style="font-size:18px">Query 1: Path from 2 to 3</span>
<span style="font-size:18px">Query 2: Path from 1 to 2, 1 to 3, and 
         2 to 3</span>
<span style="font-size:18px">Query 3: Path from 1 to 2, 1 to 3, 2 to 3, 
         and 5 to 7</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 3
list of edges {start, end, weight}= 
{{1, 2, 1}, {2, 3, 4}}</span>
<span style="font-size:18px">Q = 1
queries[] = {3}
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Query 1: Path from 1 to 2
<strong>
</strong></span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>maximumWeight()</strong>which takes integers <strong>N,</strong>&nbsp;list of&nbsp;<strong>edges</strong>&nbsp;where each edge is given by {start,end,weight}, an integer <strong>Q </strong>and a&nbsp;list of Q&nbsp;<strong>queries</strong>&nbsp;as input parameters and returns a list of integers denoting the maximum number of possible paths for each query.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(NlogN + QlogN)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ N ≤ 10<sup>4</sup></span><br>
<span style="font-size:18px">Number of edges = N - 1<br>
1 ≤ val[i] ≤ 10<sup>5</sup></span></p>
</div>