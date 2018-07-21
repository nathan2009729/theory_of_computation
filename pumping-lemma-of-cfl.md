還記得RL中的pumping lemma嗎？只要長度大於state數的字串，就一定會有重複的子字串出現，也就是說，有重複的state被使用。在CFL中也一樣，只是這一次我們不是用FA或是PDA這機器來解釋，而是用文法，也就是CFG，以及它所生成parsing tree來討論。CFL中如果有重複的rule被使用，就會有重複的子字串，當然，我們先假設這字串夠長，長到會出現重複使用的變數。

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
(當然，w長度大於某pumping length，$$p$$)
1. $$uv \neq \varepsilon$$
2. $$\mid uyv\mid \leq p$$
3. $$\{xu^iyv^iz \in L \mid i \geq 0\}$$

$$\it Proof:$$
就先假設共有$$V$$條rule，每一條rule的右邊最多可以有$$b$$個變數或terminal。想要讓字串有重複用到的字串，那至少要用到$$V+1$$條rule，因為這樣才能保證有rule被重複使用。

那想產生的有重複子字串的字串長度就至少要大於$$b^{V}$$。所以我們可以假設某一個長到可以被pump的字串，所謂的長到可以被pump，代表它的長度大於$$b^{V}$$，我們就令一個數$$p = b^{V+1}$$，而字串的長度$$\mid w \mid \geq p$$。讓$$p = b^{V+1}$$，是因為$$b^{V+1}$$是保證一定會出現重複變數的最小長度。我們再假設，我們以下討論用到的parsing tree，它是可以推導出w的所有parsing tree中，高度最小的一棵，而這棵最小的parsing tree，我們依然以上圖做表示。

(1)
那我們先來證明$$uv \neq \varepsilon$$。理由很簡單，如果有$$uv = \varepsilon$$的話，我們其實可以把字串省略成$$xyz$$，這跟假設是最小tree不符。
(2)
現在證明$$\mid uyv\mid \leq p$$。既然它的高度很高，假設比$$b^{V+1}$$還要高出許多好了，那麼可能就會有許多重複出現的變數，像是上圖的A一樣，可能這棵數除了A以外，還有變數B, C, D等等被重複使用。

那麼我們一定可以挑出某棵subtree，它的變數是所有重複的變數中，高度最低的(就是離Start最遠)，而且在這subtree裡，重複使用的變數就只有一個。就假設是上圖的A吧，那麼黃色加綠色所組成的區域，也就是只擁有一個重複變數的subtree，它的字串長度$$\mid uyv\mid$$一定$$ \leq p$$，因為這subtree，重複的變數只有一個。
(3)
要證明(3)很簡單，上面的黃色加綠色tree表示，變數A經過數次的推導，可以再推導出一個A，那麼再多推導出幾個A有何不可? 雖然一定跟w不一樣，但一定也是屬於L阿。也就是說，我們可以在多推導出幾個黃色區塊，都是屬於L。

只有一個黃色區塊的話就是$$xuyvz$$，兩個就是$$xu^2yv^2z$$，以此類推$$\{xu^iyv^iz \mid i \geq 0\}$$都是合法字串。
下圖是pumping lemma的原始證明，出自Problem Solving in Automata, Languages, and Complexity，By Ding-Zhu Du, Ker-I Ko。
![](https://i.imgur.com/Z8CzdAi.png)
![](https://i.imgur.com/XE8bGmr.png)

-----------
範例題目:

[Sipser 2.42(d)]
![](https://i.imgur.com/JclHoDh.png)
Sol:
![](https://i.imgur.com/P1WxSfp.png)

[Sipser 2.43]
![](https://i.imgur.com/kdxULzT.png)
Sol:
令$$L = \{0^p1^{2p}0^p\}$$割成$$uvxyz$$，可以分成兩個大case，就是case1: $$vxy$$只含1，跟case2: $$vxy$$含0跟1，case 2又可以分成四個小case。反正不管怎麼分，$$uxz$$都不會在L內，下圖是兩種詳細解答。
詳細sol1:
![](https://i.imgur.com/vxmxqG8.png)
sol2:
![](https://i.imgur.com/flSVTf5.png)

[Sipser 2.44]
![](https://i.imgur.com/nNdN2pE.png)
Sol:
其實很簡單吧，令 $$L = \{1^p2^{p}3^p4^p\}$$ 割成$$uvxyz$$，分成的$$vxy$$的case有四種:
$$vxy$$有1、有2、有3、有4。
詳細sol1:
![](https://i.imgur.com/OlUTtkd.png)
詳細sol2:
![](https://i.imgur.com/40iZUds.png)
![](https://i.imgur.com/W5FwMCG.png)

[Sipser 2.45]
![](https://i.imgur.com/YWBdrox.png)
Sol:
![](https://i.imgur.com/D6FNM9y.png)

[Sipser 2.57]
![](https://i.imgur.com/KQpkFvG.png)
Sol:
這題比較難吧，case分很多。
詳細sol1:
![](https://i.imgur.com/b4B5Dea.png)
詳細sol2:
![](https://i.imgur.com/ivtPnsl.png)
![](https://i.imgur.com/Wb7sIwg.png)

Reference:
[圖出處](http://web.cecs.pdx.edu/~sheard/course/CS581/notes/ContextFreePumpingLemma.pdf)
