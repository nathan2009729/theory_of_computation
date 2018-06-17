想證明兩者等價，就是要可以從一台PDA建構出CFG，反過來也要可以從CFG造出PDA。從PDA建構CFG比較難，先說這一段吧。請注意，就跟FA有分DFA跟NFA一樣，PDA也有分DPDA跟NPDA，不幸的是，DPDA和NPDA的能力並不相同，是NPDA的能力比較強，而這裡證明用到的PDA是NPDA。

先想想PDA這台機器，要怎麼用CFG中的變數來說明。我們知道輸入一字串後，PDA會從起點$$q_o$$且堆疊的符號以$$z_o$$開始，經過很多個state，如果最後可以到達final state且堆疊內無符號，代表這字串可以可以被此PDA接受。以CFG來講，起點就是文法中的第一個變數S，這S還會再變出許多變數或是非變數(就是terminal)，直到由S生出的東西全部變成terminal，便是PDA可以接受的字串。換句話說，S可以想成是從PDA起點$$q_o$$、stack是 $$z_o$$開始，到PDA其他所有state $$q_i$$。所以可以寫成

$$S \rightarrow [q_0z_oq_0] |[q_0z_oq_1]|...|[q_0z_oq_n]$$
其中$$[q_0z_oq_n]$$代表CFG的一個變數，可以想成從state $$q_o$$且堆疊的符號為$$z_o$$的狀態開始，到state $$q_n$$所產生出的字串。

以此類推，我們CFG的其他所有變數，都是長成$$[狀態i,堆疊頂端符號,狀態j]$$這樣的形式。接下來哪些$$[狀態i,堆疊頂端符號,狀態j]$$是不需要，就要看PDA的transition function了。

接下來詳細說說把PDA換成CFG的規則。我們只需要PDA的transition function，便足以轉換成相對應的CFG。PDA的transition function長成這樣:
$$((q_0,a,Z_0)(q_i,XZ_0))$$，代表在狀態$$q_0$$，tape讀到a，且stack top是$$Z_0$$時，便會進到狀態$$q_i$$，且把$$Z_0$$用$$XZ_0$$取代--其實就是把$$X$$推到stack top。
也可能長成這樣:
$$((q_0,b,X)(q_i,\varepsilon))$$，代表在狀態$$q_0$$，tape讀到b，且stack top是$$X$$時，便會進到狀態$$q_i$$，且把$$X$$用$$\varepsilon$$取代--其實就是把stack top的$$X$$給pop掉。

再說一次，CFG中所有的變數，都是$$[pXq]$$的形式，代表著機器從狀態p出發、tape上有string w、stack top是X前提下，最後可以到達狀態q且w讀取完畢堆疊也清空。

接下來就是正式規定PDA的transi換成CFG的規則並給出理由。
我們先來看case 1: $$((p,a,X)(q,\varepsilon))$$
它寫成$$[pXq] \rightarrow a$$
理由: 
很明顯，因為只執行pop動作，就是產生合法的字串。

case 2: $$((p,a,X)(r,Y))$$
它寫成$$[pXq] \rightarrow a[rYq]$$，這裡的q是PDA中的所有state，所以如果PDA中有n個state，光這transition就要寫成n個CFG rule。
理由:
此transition它pop了X並push Y，狀態由p到r，讀取了a。所以它產生的字串是什麼？是a，還有從狀態r，stack top Y的前提下產生的字串。以CFG來說，它產生的string，是a後面再跟著$$[rYq]$$所產生的字串，所以寫成$$[pXq] \rightarrow a[rYq]$$。而且到達PDA中不同的狀態還會產生不同的字串，假設共n個狀態，那就要寫成n個CFG rule。

case 3: $$((p,a,X)(r,YZ))$$
CFG的rule寫成$$[pXq] \rightarrow a[rYs][sZq]$$，s跟q是屬於PDA的任一狀態。
理由:
其實就是case 2的推廣。$$[pXq]$$可以想成在狀態p、stack top是X的前提下，到達PDA中任一狀態q所產生的字串，由$$((p,a,X)(r,YZ))$$可知讀到a時會前進至狀態r，push Y跟Z到stack裡。要把Y跟Z給pop出來也會產生字串阿，而且還要考慮到pop完Y後所在的狀態(叫作s)，同時也是要pop Z的起點。所以s不同，[rYs]跟[sZq]都會不同，所以你看，又要寫個$$n^2$$條rule了。

case 4: $$((p,a,X)(r,Y_1Y_2Y_3...Y_k))$$
CFG的rule寫成$$[pXq] \rightarrow a[rY_1s_1][s_1Y_2s_2]...[s_{k-1}Y_kq]$$
理由:
可以看得出來，就是case 3的推廣。一如既往，$$s_1$$到$$s_{k-1}$$要把所有state給排列組合上去，q也是喔！

要怎麼證明這樣的建構是對的？需要證明以下定理:
$$(q_0,w,Z_0) \vdash^* (p,\varepsilon,\varepsilon) \Leftrightarrow [q_0Z_0p ] \Rightarrow^* w$$
iff的左邊是PDA，右邊是CFG。用白話文來說，如果PDA可以在狀態p接受字串$$w$$，若且唯若CFG的相對應文法，也就是$$[q_0z_op]$$這個變數可以推導出w。

要注意，以下證明用更general的$$A \in \Gamma$$代替專門代表stack  buttom的$$Z_0$$，以$$q,q' \in Q$$代替定理中的$$q_0, p$$。所以想證明的式子要改成
$$[qAq'] \Rightarrow^* x \Leftrightarrow (q,x,A) \vdash^* (q',\varepsilon,\varepsilon)$$

$$\it proof:$$
先證明$$\Rightarrow$$的部份，對推導的step數，$$n$$，做induction。

$$\bf Basis$$
$$n=1$$，代表x是$$\varepsilon$$或是一個單一字元。我們用到的是case 1，也就是說$$[qAq'] \Rightarrow x$$是$$((q,x,A)(q',\varepsilon))$$變出來的。所以很顯然，
$$(q,x,A) \vdash (q',\varepsilon,\varepsilon)$$

$$\bf Hypothesis$$
假設 $$k \geq 1$$ and $$n \leq k$$，
if $$[qAq'] \Rightarrow^n x$$，then $$(q,x,A) \vdash^* (q',\varepsilon,\varepsilon)$$

$$\bf Inductive$$
欲證$$[qAq'] \Rightarrow^{k+1} x$$時，$$(q,x,A) \vdash^* (q',\varepsilon,\varepsilon)$$也成立。
因為$$k \geq 1$$，所以我們會用到case 4，所以字串x它派生的第一步，會是
$$[qAq'] \rightarrow \sigma[q_1B_1q_2][q_2B_2q_3]...[q_mB_mq']$$
其中$$\sigma$$是tape上可能出現的任一字元或是空字串，$$m \geq 1$$。
假設以上所出現的每一個$$[q_iB_iq_{i+1}]$$，$$i \geq 1$$，最後都會派生出字串$$x_i$$，$$[q_mB_mq']$$會派生出字串$$x_m$$。因為每個$$x_i$$它生成所需的step數小於$$k$$，由 Hypothesis可知，$$(q_i,x_i,B_i) \vdash^* (q_{i+1},\varepsilon,\varepsilon)$$且$$(q_m,x_m,B_m) \vdash^* (q',\varepsilon,\varepsilon)$$
所以$$(q,x,A) = (q,\sigma x_1x_2...x_m,A)$$，最後一定可以讀完string並把stack清空，得證。

再證明$$\Leftarrow$$的部份，對機器讀完字串並清空堆疊所需的step數，$$n$$，做induction。
$$\bf Basis$$
$$n=1$$，代表一定有$$((q,x,A)(q',\varepsilon))$$，用case 1即可得證。

$$\bf Hypothesis$$
假設 $$k \geq 1$$ and $$n \leq k$$，
對所有$$q,q' \in Q$$以及$$x \in \Sigma^*$$的所有排列組合，都可以有以下推理: if $$(q,x,A) \vdash^n (q',\varepsilon,\varepsilon)$$, then $$[qAq'] \Rightarrow^* x$$

$$\bf Inductive$$
欲證$$(q,x,A) \vdash^{k+1} (q',\varepsilon,\varepsilon)$$, then $$[qAq'] \Rightarrow^* x$$。首先假設$$x = \sigma y$$，其中$$\sigma$$是tape上可能出現的任一個字元或是空字元，$$y \in \Sigma^*$$。
所以機器在$$(q,x,A) = (q,\sigma y,A)$$這config的前提下移動的第一步，config會變成$$(q_1,y,B_1B_2B_3...B_m)$$--會這樣假設，是因為這裡假設$$((q,\sigma,A)(q_1,B_1B_2B_3...B_m))$$。
我們繼續假設，$$x_i$$是可以讓狀態從$$q_i$$到$$q_{i+1}$$，且pop掉$$B_i$$的字串，寫成形式化的樣子，就是$$(q_i,x_i,B_i) \vdash (q_{i+1},\varepsilon,\varepsilon)$$，當然，$$i$$是$$1 \leq i \leq m-1$$; 而$$(q_m,x_m,B_m) \vdash (q',\varepsilon,\varepsilon)$$。
這時開始利用Hypothesis，可以得出$$[q_iB_iq_{i+1}] \Rightarrow^* x_{i+1}$$以及$$[q_mB_mq'] \Rightarrow^* x_m$$。
再回到我們剛剛的$$(q,\sigma y,A)$$，可以推導出$$[qAq'] \\
\rightarrow \sigma [q_1B_1q_2][q_2B_2q_3]...[q_mB_mq']\\ 
= \sigma x_1x_2...x_m\\
= x$$
證畢。以下是原證明，出自Introduction to Languages and the Theory of Computation，John Martin。
![](https://i.imgur.com/lP6HYeR.png)
![](https://i.imgur.com/1RbgBer.png)
![](https://i.imgur.com/izex2oN.png)

-----------
我們來看個實際例子，知道一下從PDA推導CFG是一件多吃力的工作吧。給出以下PDA:
![](https://i.imgur.com/9E1WP2O.png)
可以整理出以下transition function:
(1)$$((q_0,a,Z_0)(q_0,XZ_0))$$  
(2)$$((q_0,a,X)(q_0,XX))$$  
(3)$$((q_0,\varepsilon,Z_0)(q_1,Z_0))$$  
(4)$$((q_0,\varepsilon,X)(q_1,X))$$  
(5)$$((q_1,b,X)(q_1,\varepsilon))$$
(6)$$((q_1,\varepsilon,Z_0)(q_2,\varepsilon))$$

來吧！Let's 噩夢！
可以從(3)，利用case 2，推導出以下CFG rule:
$$[q_0Z_0q_0] \rightarrow [q_1Z_0q_0]$$  
$$[q_0Z_0q_1] \rightarrow [q_1Z_0q_1]$$  
$$[q_0Z_0q_2] \rightarrow [q_1Z_0q_2]$$  
可以看到因為有三個狀態，所以共有三條rule。

(4)也是利用case 2，CFG rule推導如下:
$$[q_0Xq_0] \rightarrow [q_1Xq_0]$$  
$$[q_0Xq_1] \rightarrow [q_1Xq_1]$$  
$$[q_0Xq_2] \rightarrow [q_1Xq_2]$$  

(5)則是利用case 1，推導出以下CFG rule:
$$[q_1Xq_1] \rightarrow b$$
(6)也是利用case 1，CFG rule推導如下:
$$[q_1Z_0q_2] \rightarrow \varepsilon$$

(1)利用case 3推導出以下CFG rule:
![](https://i.imgur.com/zhm6xWm.png)
(2)也是利用case 3推導:
![](https://i.imgur.com/RRfH2xO.png)

Start atate S則是有:
$$S \rightarrow [q_0Z_0q_0]$$  
$$S \rightarrow [q_0Z_0q_1]$$
$$S \rightarrow [q_0Z_0q_2]$$

再給大家看一次全貌:
![](https://i.imgur.com/UHkARy4.png)
裡面一定有很多沒用到的variable，為了方便，我們把variable重新命名如下:
![](https://i.imgur.com/GVs1XRm.png)

現在開始刪除不需要的variable。首先，產生出terminal的一定不能刪，所以
$$H \rightarrow \varepsilon$$ 跟
$$R \rightarrow b$$要留下。

那麼$$ \rightarrow $$的右邊有H跟R的，自然要留下。所以E，也就是$$[q_0Z_0q_2]$$，產生了H所以要留下，S裡的E當然會留下。K既然產生了R，當然也留下。
接下來檢討最後的六行，CDEJKL，所產生的一大堆rule。現在知道了，只要不是S、H、E、K、R所組成的，都刪。像是$$C \rightarrow aKF$$，F不產生terminal阿，所以這條就刪掉。最後我們可以發現C、D、J跟L的所有rule全刪，只剩下E的aKH跟K的aKR。

整理一下最後的結果，沒刪的有:
$$S \rightarrow E$$
$$E \rightarrow H$$
$$E \rightarrow aKH$$
$$H \rightarrow \varepsilon$$
$$K \rightarrow R$$
$$K \rightarrow aKR$$
$$R \rightarrow b$$

再化簡一下，變成了
$$S \rightarrow aK \mid \varepsilon$$
$$K \rightarrow b \mid aKb$$

這是什麼語言？其實就是$${a^nb^n}$$。有沒有覺得推導這麼多variable都是垃圾，出來的結果很空虛?

reference:
[rutgers上課講義](https://www.cs.rutgers.edu/~ma635/courses/cs154/lectures/lec9.pdf)
[實際例子出處](http://cs475.cs.ua.edu/PDA%20to%20CFG.pdf)