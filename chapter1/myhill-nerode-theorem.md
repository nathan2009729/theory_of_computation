要看這定理之前，先來看一個簡單的FA，叫它M吧，M能接受的語言又可以被稱為L(M)。

![](https://i.imgur.com/Nes8TmL.gif)

這個FA的3個state，其實我們可以把它們稱為此語言的3個equivalence class(簡稱e.c.)，每個e.c.是一個很多string所構成的集合。最左邊的start state我們可以把它寫成[$$\varepsilon$$]，由$$\varepsilon$$代表這個e.c.，可以由圖知，[$$\varepsilon$$]={$$\varepsilon$$, aaa, aab,...}，這set同時也是走到start state時所產生的string的集合。

FA，顧名思義"有限"自動機，FA裡的圈圈，也就是state，一定有個限度。也就是說，如果今天給你一個language，告訴你它是regular的，那它的e.c.數目就一定是有限的，因為從上面得知，對RE來說，每個e.c.都是一個state，state有限，e.c.數量當然有限。

現在來解釋，為什麼要把state叫成e.c.。觀察第一張圖，[$$\varepsilon$$]這個集合裡的不管哪一個字串，只要再加上a，通通可以到達accept state。舉個例子，aaa再多個a，就可以到達accept state; aab同樣再多個a，也可以到達accept state。這時我們就說，aaa $$R_L$$ aab，因為它們接上同一個string，就可以被L(M)接受。所以$$R_L$$的正式定義是，如果 $$x R_L y$$，代表對於任何string z，string xz屬於L若且唯若(if and only if, iff)string yz屬於L。

數學上，有一種關係叫equivalence relation，就是說對於兩種對象的某種關係，符合reflexive, symmetric,跟transitive。舉個具體的例子，台北到台中，這個"到"，就是一個equivalence relation。它符合reflexive，因為能從台北到台北，當然能從台北到台北; 符合symmetric，因為能從台北到台中，當然能從台中到台北; 符合transitive，因為能從台北到台中，而且也可以從台中到高雄的話，那就可以從台北到高雄。

可以自己驗證一下，$$R_L$$其實就是一種equivalence relation。而equivalence relation形成的集合，就是equivalence class(大概)，因為以上圖來說，aaa $$R_L$$ aab也$$R_L$$ aba，總之，所有三個由a或b組成的string，互相都有$$R_L$$關係，也都屬於同一個e.c.。

而Myhill-Nerode定理，其實就是告訴你，如果一個language L它是regular，那麼它的equivalence class數量，也可以寫成index($$R_L$$)，一定是有限的。它還指出了，minimum DFA的狀態數跟index($$R_L$$)相等。所以這定理提供了可以判定language是否regular的方法，其實也告訴你該怎麼化簡DFA，以減少冗餘的狀態。不過化簡DFA用這定理滿費力氣的，通常是用table-filling algorithm。

來看看該怎麼應用Myhill-Nerode定理來證明某個語言非正規吧。比如$$B = \{0^n1^n : n \geq 0\}$$，那麼它的e.c.會有哪些呢? 比如說，某個e.c.，是接受$$0^n$$，那麼這個e.c.只要再接受$$1^n$$，就可以被$$B$$所接受。還有不一樣的e.c.，像是$$0^m$$，那麼這個e.c.只要再接上跟$$1^n$$不同的字串，像是$$0^{n-m}1^n$$，或是$$0^{m-n}1^n$$也可以被$$B$$所接受。但問題來了，這裡沒限定$$n$$的範圍，所以$$0^m$$其實根據m值不同，會有無數個e.c.。結論$$index(R_L) = \infty$$，大家可以回家了，它根本就找不到FA。

一般的上課講義，利用Myhill-Nerode定理證明某個語言非正規時，都會提到另一個概念:   distinguishable。就是說兩個不同的string，假設是x跟y，接上同一string，z，一個會屬於L但一個不屬於，就說x跟y是distinguishable，其實就是意指x跟y是屬於不同的e.c.。看第一張圖，aaa跟aaab就是distinguishable的。道理還是一樣，e.c.無限代表不是正規，所以如果跟y是distinguishable的x有無數個，當然就不是正規了。

所以上面的範例，其實一般證明會寫成如下:
考慮兩string $$x = 0^n$$跟$$y = 0^m$$，where $$n \neq m$$，令$$z = 1^n$$，那麼$$xz \in L$$但$$yz \notin L$$。也就是說$$0^n$$跟$$0^m$$在所有$$n \neq m$$都是distinguishable，所以L非regular，QED。

$$\bf Example\;2:$$  
show that $$L = \{ww|w \in \{0,1\}^*\}$$ is not regular.
$$\it proof:$$
consider $$x = 0^n$$, $$y = 0^m$$ and $$z = 1^n0^n1^n$$，$$xz \in L$$ but $$yz \notin L$$，$$z$$ distinguishes $$0^n$$and$$0^m$$，QED。

$$\bf Example\;3:$$  
show that $$L = \{w\in \Sigma^*|w = w^R\}$$ is not regular.
$$\it proof:$$
Consider $$x = a^ib$$, $$y = a^jb$$ and $$z = a^i$$，$$xz \in L$$ but $$yz \notin L$$. So for all $$i \neq j$$, $$x$$ and $$y$$ are distinguishable，QED。

$$\bf Example\;3.1:$$  
show that $$L = \{xx^R|x \in \{0,1\}^*\}$$ is not regular.
$$\it proof:$$
For any $$x,y \in 0^*1$$ with $$x \neq y$$, we know that $$xx^R \in L$$ but $$yx^R \notin L$$. Thus, any two strings in $$0^*1$$ must belong to two different e.c. of $$R_L$$. This means that $$index(R_L) = \infty$$. Thus, L is not regular.

$$\bf Example\;4:$$  
show that $$L = \{0^m1^n|gcd(m,n) = 1\}$$ is not regular.
$$\it proof:$$
For any two different primes p and q,  $$0^q1^p \in L$$ and $$0^p1^p \notin L$$.Therefore, $$0^p$$ and $$0^q$$ are not in the same class of $$R_L$$. Since there are an infinite number of primes, we have $$index(R_L) = \infty$$. Thus, L is not regular.

所以如果想裝成大神講幹話，就是要在某些問題無法用pumping lemma解決時，很霸氣的說：

想了幾秒鐘乾脆用最強的Myhill-Nerode theorem 作掉。

這時同學就會投以崇拜的眼神，因為大家根本看不懂這定理在寫三小，搞不好連看都沒看過。要記得喔，那串英文一定要念出來(雖然我不會念)，還有，不能像剛剛上面我寫的一樣講成"定理"，要說成"Theorem"，這才顯得高人一等。雖然看完上面的解釋跟範例可能覺得他媽的regular language是有限state不是廢話嗎，但是大部分人大概不會看到這篇吧。

其實光是靠這個定理，就有辦法直接製造出最小DFA，也就是找到e.c.，把每個e.c.當成一個state即可。但一般哪會這樣做，乾脆直接先亂畫出一個可以接受L的NFA，再轉成對應的DFA，再檢查能不能化簡，大概比找e.c.快吧。