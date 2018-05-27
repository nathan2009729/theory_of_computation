這章的一個重點是pumping lemma，就是一個測試是否為非RL的lemma。要注意，只要language不符合它，就是非RL，但如果某language符合pumping lemma，並不代表它是正規的。想證明language是RL，還是得找到它的NFA才行。

那麼，非RL的language有什麼特性？就是不被任何NFA接受，但是你找不到某languag的NFA並不代表它不是RL，可能只是你笨所以沒找到。

看一下下面的範例(出自[M.Sipser]習題)，乍看之下不是RL，但其實是。
![](https://i.imgur.com/YYvxgLd.png)  
解題思路:  
其實要知道，隨便一個字串出來要判斷它是不是屬於B，k可以隨便定一個很小的數字，就假設k是1好了。所以可以定另一個語言A，它的定義是:
![](https://i.imgur.com/KGzI7s1.png)

要讓B跟A相等，就是$$1^ky = 11^{k-1}(0^*1^k)\Sigma^*$$，也就是說，A裡的y需要至少2k-1個1，不過題目條件是$$k \geq 1$$，所以第一個1的後面只要再有一個1就好。  
完整解答:  
![](https://i.imgur.com/iwAv6Ne.png)

另一個類似的題目及其解法(其實只是改成$$k \geq 2$$):  
![](https://i.imgur.com/n1sjN0N.png)

想一下NFA的本質，其實就是有限步驟，圈圈的數量一定是有限度的。所以如果看到一個RE，它可以變得無限長，可是它又是一個RL，代表它產生的那一串很長的string一定有些是由NFA中的loop產生的。順代提一句廢話，如果這個language所產生的語言集合是有限的話，當然一定是RL了，因為只要針對該語言集合的每一個字串造NFA，再把它們union起來就可以。

比如下圖:  
![](https://i.imgur.com/7x0Td2a.png)

它就可以產生01111111111111110011111111111這麼長的字串，但是它只有兩個state。原因就是可以在$$q_1$$ 一直loop。

所以看到一個可以變無限長的language，想知道它是不是RL，就先假設它有一個FA可以接受。那麼，它的FA應該會是長得像下面那樣子：

![](https://i.imgur.com/xwzXfaU.png)

有個開始的state跟接受的state，中間會有個loop才對。而既然有了這FA，不管中間的loop走幾次(可以不走也可以走k次)應該都是這language的成員才對。如果發現中間的loop多走了一次或是不走就不屬於這language，代表假設矛盾，這language沒有FA。

pumping lemma的正式定義是:
如果L是RL，那麼有一個pumping length p > 0，如果$$w \in L$$且$$\|w\| \geq p$$，那麼w可以被被切成xyz，where
1. $$\|xy\| \leq p$$
2. $$y \ne \varepsilon$$
3. $$xy^kz \in L$$, for every $$\|k\| \geq 0$$

所謂的pumping length，就是長到可以出現重複子字串的長度，也就是至少比state數還多。