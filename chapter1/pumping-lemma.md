這章的一個重點是pumping lemma，就是一個測試是否為非RL的lemma。要注意，只要language不符合它，就是非RL，但如果某language符合pumping lemma，並不代表它是正規的。想證明language是RL，還是得找到它的NFA才行。

那麼，非RL的language有什麼特性？就是不被任何NFA接受，但是你找不到某languag的NFA並不代表它不是RL，可能只是你笨所以沒找到。

想一下NFA的本質，其實就是有限步驟，圈圈的數量一定是有限度的。所以如果看到一個RE，它可以變得無限長，可是它又是一個RL，代表它產生的那一串很長的string一定有些是由NFA中的loop產生的。

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