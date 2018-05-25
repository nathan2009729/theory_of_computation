Regular language(RL)，便是可以用finite automata(FA)辨識的語言。finite automata長的像是這樣：
![](https://i.imgur.com/bXWLuwN.png)

或是這樣：

![](https://i.imgur.com/qd4unXg.png)

或是這樣：
![](https://i.imgur.com/HFzgZy7.png)

等等。
圖中有兩個圈圈的是accept。

而FA又分成DFA跟NFA(Deterministic,Nondeterministic)，差別在於每個state是否會有超過一種的選擇。比如上圖在$$q_2$$這個state遇到a時可以繼續留在$$q_2$$或是前往$$q_3$$，所以是NFA，反之則是DFA。

乍看之下NFA的識別能力比較強，但其實DFA跟NFA的識別能力是等價的，也就是說，NFA可以識別的語言，DFA也可以識別。要證明這件事，就需要給出一個方法，可以把NFA轉換成DFA。要注意的是Pushdown Automata(PDA)的Deterministic跟Nondeterministic能力就不同了--Nondeterministic版本的PDA比較厲害。

而某language是regular $$\Leftrightarrow$$ 有NFA可辨識該language。

而Regular language在union,concatenation,star等operation下是close的。也就是說，RL經過這三符號運算依然是RL。
證明圖示如下：  
union:  
![](https://i.imgur.com/ZHQTxTi.png)


concatenation:  
![](https://i.imgur.com/GWgl18B.png)

star:  
![](https://i.imgur.com/co1UIMA.png)

$$\delta(r_i,w_{i+1}) = r_{i+1}$$