這裡收錄一些有趣的問題:

1.[M.Sipser 1.57]
乍看下毫無頭緒，其實可以利用pumping lemma。因為A是RL，所以A中必有某字串w，它可以切成xyz且一定會符合pumping lemma的三條件。所以$$L_1 =xy^{2i}z$$ for $$i \geq 0$$一定也是屬於A，且很明顯是infinite。因為$$L_1$$可以被寫成$$L_1 =x(yy)^*z$$，所以很明顯是regular。
好，那麼disjoint是什麼？就是完全沒交集。如果A可以被切成兩個完全沒交集的語言，假設一個叫$$L_1$$，一個就是$$A - L_1$$。$$A - L_1$$其實又可以寫成$$A \cap \overline{L_1}$$，既然已知$$A$$跟$$L_1$$都是regular，那麼只要確認RL close under intersection跟complementation就可以了。
詳細解答:  
![](https://i.imgur.com/82NUUDN.png)  
詳細解答2:  
![](https://i.imgur.com/kF5u5vH.png)
![](https://i.imgur.com/9Sp3EDe.png)
![](https://i.imgur.com/nm0oyTe.png)

2.
重新看一次之前可以找到FA的題目[M.Sipser 1.71a]:  
![](https://i.imgur.com/YYvxgLd.png)    
再來看下面例題:  
![](https://i.imgur.com/kK3AKrL.png)
![](https://i.imgur.com/4xyUkqm.png)  
都需要用到pumping lemma。

3.在解決[M.Sipser 1.66]前，可以先看這類似的問題:  
![](https://i.imgur.com/uLp9OAr.png)    
及其解答:  
![](https://i.imgur.com/2uCeG8R.png)
![](https://i.imgur.com/RHD3ARJ.png)
![](https://i.imgur.com/L7KCj1D.png)
![](https://i.imgur.com/cSpWpbm.png)



