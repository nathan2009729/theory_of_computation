還記得RL中的pumping lemma嗎？只要長度大於state數的字串，就一定會有重複的子字串出現，也就是說，有重複的state被使用。在CFL中也一樣，只是這一次我們不是用FA或是PDA這機器來解釋，而是用文法，也就是CFG，以及它所生成parsing tree來討論。CFL中如果有重複的rule被使用，就會有重複的子字串。

就先假設共有$$V$$條rule，每一條rule的右邊最多可以有$$m$$個變數或terminal。想要讓字串有重複用到的字串，那至少要用到$$V+1$$條rule，因為這樣才能保證有rule被重複使用。

那想產生的有重複子字串的字串長度就至少要大於$$m^{V}$$。所以我們可以假設某一個長到可以被pump的字串，它的長度$$n \geq m^{V}$$，所產生的parsing tree高度會大於$${V}$$。

提供一個簡單的想法。這個夠長的字串，它的parsing tree應該會是長成下面這樣子:
![](https://i.imgur.com/p6oYKYz.png)
某個變數A它用了兩次。而上圖的CFG的文法可以寫成以下的形式:
$$S \Rightarrow^* xAz$$
$$A \Rightarrow^* uAv$$
$$A \Rightarrow^* y$$
大寫的是變數，小寫的是terminal。

題外話，CFG會寫成兩個terminal夾著一個變數，其實可以簡單的理解為因為CFG可以比RL識別更多語言。RL其實也可以寫成這種文法的形式: 如果在FA中，一個state $$q_i$$遇到tape上的字元a後，會進入state $$q_{i+1}$$的話，我們就可以寫成文法:
$$q_i \rightarrow aq_{i+1}$$
而RL無法識別的$$\{a^nb^n \mid n \geq 0\}$$，可以寫成CFL文法
$$S \rightarrow aSb \mid \varepsilon$$，其實也只是在S的右邊多個terminal b罷了。

回來正題。這圖其實就很清楚的告訴了我們，CFL的pumping lemma其實就是把字串w砍成五段，因為rule A可以重複使用，所以第二段跟第四段，也就是$$u,v$$是重複任意次都會屬於該CFL。

接下來就來看看pumping lemma正式的定義:
(當然，w長度大於n)
1. $$uv \neq \varepsilon$$
2. $$\mid uyv\mid \leq n$$
3. $$\{xu^iyv^iz \in L \mid i \geq 0\}$$

Reference:
[圖出處](http://web.cecs.pdx.edu/~sheard/course/CS581/notes/ContextFreePumpingLemma.pdf)
