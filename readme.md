要件 https://cdn.intra.42.fr/pdf/pdf/173709/en.subject.pdf

https://web.archive.org/web/20250429115023/https://42-evaluation-sheets-hub.vercel.app/Cursus/CPP05/

理解しました。この課題文を1行ずつ、以下のフォーマットで整理します。

---

### Compiling

**原文**
Compiling
**翻訳**
コンパイルについて
**意味**
ここではコードのコンパイルに関するルールを説明している。
**何をすればいいか**
以下のコンパイル条件を守ること。

---

**原文**
• Compile your code with c++ and the flags -Wall -Wextra -Werror
**翻訳**
c++ コマンドで `-Wall -Wextra -Werror` フラグを付けてコンパイルすること。
**意味**
警告を全て有効にし、警告が出たらエラーとして扱う設定でコンパイルしなければならない。
**何をすればいいか**
必ずこのオプションをつけて `c++` でビルドする。

---

**原文**
• Your code should still compile if you add the flag -std=c++98
**翻訳**
`-std=c++98` フラグを追加してもコンパイルが通るようにすること。
**意味**
コードは C++98 標準に準拠していなければならない。
**何をすればいいか**
C++98 で使えない機能（C++11以降の構文など）を使わない。

---

### Formatting and naming conventions

**原文**
Formatting and naming conventions
**翻訳**
フォーマットと命名規則
**意味**
ディレクトリ名やファイル名、クラス名などのルールを定めている。
**何をすればいいか**
ここで決められた規則に従って名前や形式を揃える。

---

**原文**
• The exercise directories will be named this way: ex00, ex01, ... , exn
**翻訳**
課題ディレクトリは `ex00, ex01, ... , exn` の形式で命名すること。
**意味**
フォルダの名前は必ずこの形式で統一する必要がある。
**何をすればいいか**
課題ごとに `ex00` などのディレクトリを作成する。

---

**原文**
• Name your files, classes, functions, member functions and attributes as required in the guidelines.
**翻訳**
ファイル、クラス、関数、メンバ関数、属性はガイドラインに従って命名すること。
**意味**
命名ルールは明示的に決められており、それに従う必要がある。
**何をすればいいか**
課題で指定されている命名規則を必ず守る。

---

**原文**
• Write class names in UpperCamelCase format. Files containing class code will always be named according to the class name. For instance: ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you have a header file containing the definition of a class "BrickWall" standing for a brick wall, its name will be BrickWall.hpp.
**翻訳**
クラス名は **UpperCamelCase**（例: `ClassName`）で書くこと。クラスを含むファイル名はクラス名と一致させること。例: `ClassName.hpp` / `ClassName.cpp` / `ClassName.tpp`。例えば「BrickWall」というクラスがあるなら、そのヘッダファイルは `BrickWall.hpp` とする。
**意味**
クラス名とファイル名は対応させる必要がある。
**何をすればいいか**
クラスを作る際は UpperCamelCase にし、ファイルも同じ名前にする。

---

**原文**
• Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output.
**翻訳**
特に指定がない限り、すべての出力メッセージは改行で終わり、標準出力に表示すること。
**意味**
出力の最後に `\n` を必ず付けるルール。
**何をすればいいか**
printfやcoutの出力の最後に改行を入れる。

---

**原文**
• Goodbye Norminette! No coding style is enforced in the C++ modules. You can follow your favorite one. But keep in mind that code your peer evaluators can’t understand is code they can’t grade. Do your best to write clean and readable code.
**翻訳**
Norminette とはさようなら！C++ モジュールではコーディングスタイルの強制はない。好きなスタイルを使える。ただし、採点者が理解できないコードは評価できないので、できる限り読みやすいコードを書くこと。
**意味**
コーディング規約は強制されないが、可読性は重要。
**何をすればいいか**
整ったインデントや分かりやすい名前を意識して書く。

---

### Allowed/Forbidden

**原文**
Allowed/Forbidden
**翻訳**
使用可能・禁止事項
**意味**
使っていいものと使ってはいけないものをまとめている。
**何をすればいいか**
以下のルールを守ってコードを書く。

---

**原文**
You are not coding in C anymore. Time to C++! Therefore:
**翻訳**
もうC言語ではない。C++を書く時だ！
**意味**
C言語ではなくC++の書き方に切り替える必要がある。
**何をすればいいか**
C言語的な書き方をやめ、C++らしい書き方を使う。

---

**原文**
• You are allowed to use almost everything from the standard library. Thus, instead of sticking to what you already know, it would be smart to use the C++-ish versions of the C functions you are used to as much as possible.
**翻訳**
標準ライブラリのほとんどすべてを使用できる。したがって、これまで使っていたCの関数にこだわらず、C++版をできるだけ使う方が良い。
**意味**
C++標準ライブラリを積極的に使うこと。
**何をすればいいか**
例: `printf` ではなく `std::cout` を使う、`malloc` ではなく `new` を使う。

---

**原文**
• However, you can’t use any other external library. It means C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: \*printf(), \*alloc() and free(). If you use them, your grade will be 0 and that’s it.
**翻訳**
ただし、外部ライブラリは一切使用できない。C++11（および派生形）やBoostライブラリは禁止。以下の関数も禁止: `printf()` 系, `*alloc()` 系, `free()`。これらを使うと成績は無条件で0になる。
**意味**
使えるのはC++98の標準ライブラリのみ。それ以外は禁止。
**何をすればいいか**
禁止関数を使わずに、C++の標準的な機能（`iostream`, `new/delete` など）で書く。

はい、この部分も1行ずつ整理します。

---

**原文**
• Note that unless explicitly stated otherwise, the using namespace \<ns\_name> and friend keywords are forbidden. Otherwise, your grade will be -42.
**翻訳**
明示的に許可されていない限り、`using namespace <ns_name>` と `friend` キーワードは禁止。違反すると評価は -42。
**意味**
名前空間をまとめてimportする書き方と`friend`指定は禁止。
**何をすればいいか**
`using namespace std;` を使わず、必要なものだけ `std::` をつけて使う。`friend` も禁止。

---

**原文**
• You are allowed to use the STL only in Modules 08 and 09. That means: no Containers(vector/list/map, and so forth) and no Algorithms(anything that requires including the <algorithm> header) until then. Otherwise, your grade will be -42.
**翻訳**
STLの使用はModule 08と09だけで許可される。それまでは、コンテナ（vector, list, map など）もアルゴリズム（`<algorithm>` が必要なもの）も禁止。違反すれば評価は -42。
**意味**
Module 07までSTLは使えない。
**何をすればいいか**
`vector`や`sort`を使わず、自作で必要なものを実装する。

---

### A few design requirements

**原文**
• Memory leakage occurs in C++ too. When you allocate memory (by using the new keyword), you must avoid memory leaks.
**翻訳**
C++でもメモリリークは起こる。`new`でメモリを確保した場合は、必ずリークを避けること。
**意味**
動的確保したら解放も必要。
**何をすればいいか**
`delete`や`delete[]`を必ず対応させる。

---

**原文**
• From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form, except when explicitly stated otherwise.
**翻訳**
Module 02〜09では、特に指示がない限りクラスを「正統カノニカルフォーム」で設計すること。
**意味**
コンストラクタ、コピーコンストラクタ、代入演算子、デストラクタを正しく実装する必要がある。
**何をすればいいか**
OCF（Orthodox Canonical Form）を必ず実装。

---

**原文**
• Any function implementation put in a header file (except for function templates) means 0 to the exercise.
**翻訳**
関数の実装をヘッダに書いた場合（関数テンプレートを除く）、その課題の評価は0点。
**意味**
実装は`.cpp`に書くべきで、`.hpp`には宣言だけ。
**何をすればいいか**
普通の関数はcppに書き、テンプレートだけヘッダに置く。

---

**原文**
• You should be able to use each of your headers independently from others. Thus, they must include all the dependencies they need. However, you must avoid the problem of double inclusion by adding include guards. Otherwise, your grade will be 0.
**翻訳**
各ヘッダは他に依存せず単独で使えるべき。そのため必要な依存は自分でインクルードする。ただし二重インクルードを避けるためにインクルードガードを入れること。守らなければ評価は0。
**意味**
ヘッダは自己完結型にしつつ、多重定義を防ぐ仕組みを入れる。
**何をすればいいか**
`#ifndef / #define / #endif` または `#pragma once` を必ず書く。

---

### Read me

**原文**
• You can add some additional files if you need to (i.e., to split your code). As these assignments are not verified by a program, feel free to do so as long as you turn in the mandatory files.
**翻訳**
必要なら追加ファイルを作ってもよい（コード分割など）。この課題は自動テストされないので、必須ファイルさえ提出すれば問題ない。
**意味**
補助的なソースファイルを自由に作れる。
**何をすればいいか**
main分割やutilsファイルを追加して整理してよい。

---

**原文**
• Sometimes, the guidelines of an exercise look short but the examples can show requirements that are not explicitly written in the instructions.
**翻訳**
課題の指示文は短いことがあるが、例に明記されていない要件が含まれている場合がある。
**意味**
例文も必ず読んで仕様を把握しなければならない。
**何をすればいいか**
課題例を必ず確認し、仕様のヒントを拾う。

---

**原文**
• Read each module completely before starting! Really, do it.
**翻訳**
始める前に各モジュールを完全に読め！本当に読め。
**意味**
モジュール全体を理解してから着手すべき。
**何をすればいいか**
課題をやる前に説明全体を読む。

---

**原文**
• By Odin, by Thor! Use your brain!!!
**翻訳**
オーディンにかけて、トールにかけて！頭を使え！！！
**意味**
ただコピペせず、自分で考えること。
**何をすればいいか**
常に自分で設計・理解して進める。

---

**原文**
Regarding the Makefile for C++ projects, the same rules as in C apply (see the Norm chapter about the Makefile).
**翻訳**
C++プロジェクトのMakefileはCと同じルールに従う（NormのMakefile章を参照）。
**意味**
Makefileの書き方はC課題と同じ。
**何をすればいいか**
`all/clean/fclean/re`ターゲットを作り、フラグや依存関係を正しく設定。

---

**原文**
You will have to implement a lot of classes. This can seem tedious, unless you’re able to script your favorite text editor.
**翻訳**
多くのクラスを実装しなければならない。これは退屈に感じるかもしれないが、お気に入りのエディタをスクリプト化すれば楽になる。
**意味**
繰り返し作業が多いが、自動化すれば効率化できる。
**何をすればいいか**
コードスニペットやテンプレートを用意して作業を楽にする。










はい、この課題部分も1行ずつ整理します。

---

### Chapter IV

**原文**
Chapter IV
**翻訳**
第4章
**意味**
この章の課題を始める。
**何をすればいいか**
以下の Exercise 00 を解く。

---

**原文**
Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
**翻訳**
課題00: 「ママ、僕が大きくなったら官僚になりたい！」
**意味**
この課題のテーマ名。
**何をすればいいか**
「Bureaucrat」クラスを作る課題に取り組む。

---

**原文**
Exercise : 00
Mommy, when I grow up, I want to be a bureaucrat!
**翻訳**
課題: 00
「ママ、僕が大きくなったら官僚になりたい！」
**意味**
課題タイトルの再掲。
**何をすればいいか**
内容は同じ、Bureaucrat クラスを作る。

---

**原文**
Turn-in directory: ex00/
**翻訳**
提出ディレクトリ: `ex00/`
**意味**
提出する課題ファイルはこのフォルダに入れる。
**何をすればいいか**
`ex00/` フォルダを作って、その中にファイルを置く。

---

**原文**
Files to turn in: Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
**翻訳**
提出するファイル: `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}`, `Bureaucrat.cpp`
**意味**
必須の提出ファイルが指定されている。
**何をすればいいか**
このファイル名で作成して提出する。

---

**原文**
Forbidden functions: None
**翻訳**
禁止関数: なし
**意味**
この課題では使ってはいけない関数はない。
**何をすればいいか**
自由に標準ライブラリを使える。

---

**原文**
Please note that exception classes do not have to be designed in Orthodox Canonical Form. However, every other class must follow it.
**翻訳**
例外クラスは **正統カノニカルフォーム（OCF）** を設計する必要はない。ただし、それ以外のクラスは必ず従わなければならない。
**意味**
例外クラスは簡単に書いてよいが、通常のクラスは OCF が必須。
**何をすればいいか**
`Bureaucrat` クラスは OCF で実装。例外クラスはシンプルにOK。

---

**原文**
Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
Sounds fun? No? Too bad.
**翻訳**
オフィス、廊下、書類、待ち行列という人工的な悪夢を設計しよう。楽しそう？そうでもない？残念だがやるんだ。
**意味**
課題の雰囲気を演出しているだけ。
**何をすればいいか**
実装内容に集中する。

---

**原文**
First, start with the smallest cog in this vast bureaucratic machine: the Bureaucrat.
**翻訳**
まず、この巨大な官僚機構の最小単位から始めよう: **Bureaucrat**。
**意味**
最初の課題は Bureaucrat クラスの設計。
**何をすればいいか**
`Bureaucrat` クラスを作る。

---

**原文**
A Bureaucrat must have:
**翻訳**
Bureaucrat は次を持たなければならない:
**意味**
クラスに必須のメンバ条件。
**何をすればいいか**
以下の要素を実装する。

---

**原文**
• A constant name.
**翻訳**
定数の名前（変更不可の名前）。
**意味**
`const std::string name;` のように一度決めたら変更できない名前。
**何をすればいいか**
Bureaucrat の名前を `const` メンバとして実装。

---

**原文**
• A grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
**翻訳**
等級は 1（最高位）から 150（最低位）までの範囲で持つ。
**意味**
Bureaucrat の評価値。
**何をすればいいか**
`int grade;` を保持し、範囲は \[1,150] に制限する。

---

**原文**
Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
**翻訳**
無効な等級で Bureaucrat を生成しようとした場合は例外を投げること。例外は `Bureaucrat::GradeTooHighException` または `Bureaucrat::GradeTooLowException`。
**意味**
コンストラクタで grade のチェックが必要。
**何をすればいいか**
コンストラクタ内で範囲外なら例外をスローする。

はい、この部分も1行ずつ整理します。

---

**原文**
You will provide getters for both attributes: getName() and getGrade().
**翻訳**
2つの属性に対してゲッターを用意すること: `getName()` と `getGrade()`。
**意味**
名前と等級を取得する関数を作る必要がある。
**何をすればいいか**
`std::string getName() const;` と `int getGrade() const;` を実装。

---

**原文**
You must also implement two member functions to increment or decrement the bureaucrat’s grade.
**翻訳**
官僚の等級を **インクリメント** または **デクリメント** する2つのメンバ関数を実装すること。
**意味**
等級を上げる関数と下げる関数を用意する。
**何をすればいいか**
`void incrementGrade();` `void decrementGrade();` を作る。

---

**原文**
If the grade goes out of range, both functions must throw the same exceptions as the constructor.
**翻訳**
等級が範囲外になった場合、両方の関数はコンストラクタと同じ例外を投げなければならない。
**意味**
grade を変更した時に1未満や150超えになったら例外を投げる。
**何をすればいいか**
increment/decrement 内で範囲チェック → 例外をスロー。

---

**原文**
Remember, since grade 1 is the highest and 150 the lowest, incrementing a grade 3 should result in a grade 2 for the bureaucrat.
**翻訳**
忘れないように。等級1が最高で150が最低なので、等級3をインクリメントすると等級2になる。
**意味**
インクリメントは「数値を小さくする」操作。
**何をすればいいか**
`incrementGrade()` は `grade--`、`decrementGrade()` は `grade++` と実装する。

---

**原文**
The thrown exceptions must be catchable using try and catch blocks:
**翻訳**
スローされた例外は `try` と `catch` ブロックで捕捉できなければならない。
**意味**
例外クラスは `std::exception` を継承して実装する必要がある。
**何をすればいいか**
`class GradeTooHighException : public std::exception { ... };` を作る。

---

**原文**
try
{
/\* do some stuff with bureaucrats */
}
{
catch (std::exception & e)
/* handle exception \*/
}
**翻訳**

```cpp
try {
    /* bureaucrat に関する処理 */
}
catch (std::exception & e) {
    /* 例外処理 */
}
```

**意味**
例外は標準的なtry-catchで処理できる。
**何をすればいいか**
テストコードで例外が投げられ、catchできることを確認する。

---

**原文**
You must implement an overload of the insertion («) operator to print output in the following format (without the angle brackets): <name>, bureaucrat grade <grade>.
**翻訳**
挿入演算子（`<<`）をオーバーロードし、次の形式で出力できるようにする（山かっこは出力しない）：
`name, bureaucrat grade grade`
**意味**
`std::cout << obj;` で指定フォーマットが出るようにする必要がある。
**何をすればいいか**
グローバル関数 `std::ostream& operator<<(std::ostream&, const Bureaucrat&);` を実装。

---

**原文**
As usual, submit some tests to prove that everything works as expected.
**翻訳**
いつも通り、すべてが期待通りに動くことを証明するテストを提出すること。
**意味**
main.cpp に動作確認コードを書く必要がある。
**何をすればいいか**
異常値・境界値を試すテストを main.cpp に書いて提出。
















はい、Exercise 01 の部分も1行ずつ整理します。

---

**原文**
Chapter V
**翻訳**
第5章
**意味**
次の章の課題が始まる。
**何をすればいいか**
Exercise 01 を進める。

---

**原文**
Exercise 01: Form up, maggots!
**翻訳**
課題01: 整列しろ、新兵ども！
**意味**
課題タイトル。
**何をすればいいか**
「Form」クラスを作成する課題。

---

**原文**
Exercise : 01
Form up, maggots!
**翻訳**
課題: 01
整列しろ、新兵ども！
**意味**
タイトル再掲。
**何をすればいいか**
対象は Form クラス。

---

**原文**
Turn-in directory: ex01/
**翻訳**
提出ディレクトリ: `ex01/`
**意味**
この課題は ex01 フォルダにまとめる。
**何をすればいいか**
`ex01/` を作成してファイルを入れる。

---

**原文**
Files to turn in: Files from the previous exercise + Form.{h, hpp}, Form.cpp
**翻訳**
提出ファイル: 前の課題のファイル + `Form.{h,hpp}`, `Form.cpp`
**意味**
Bureaucrat関連も含め、Formファイルを追加する必要がある。
**何をすればいいか**
ex00 のファイルに加えて Form クラスのファイルを作って提出。

---

**原文**
Forbidden functions: None
**翻訳**
禁止関数: なし
**意味**
この課題でも禁止関数はない。
**何をすればいいか**
自由に標準ライブラリを使える。

---

**原文**
Now that you have bureaucrats, let’s give them something to do. What better activity could there be than filling out a stack of forms?
**翻訳**
官僚（Bureaucrat）ができたので、彼らに仕事を与えよう。書類の山に記入する以上にふさわしい仕事はあるだろうか？
**意味**
次は Bureaucrat に Form を扱わせる課題。
**何をすればいいか**
Form クラスを実装して Bureaucrat と関連づける。

---

**原文**
Let’s create a Form class. It has:
**翻訳**
Form クラスを作成する。持つべきものは以下:
**意味**
Form クラスの属性リスト。
**何をすればいいか**
以下のメンバ変数を private に定義。

---

**原文**
• A constant name.
**翻訳**
定数の名前。
**意味**
Form の名前は変更できない。
**何をすればいいか**
`const std::string name;` を定義。

---

**原文**
• A boolean indicating whether it is signed (at construction, it is not).
**翻訳**
署名されているかを示す bool 値（コンストラクタでは false）。
**意味**
署名状態を保持する。
**何をすればいいか**
`bool isSigned;` を定義し、初期値は false。

---

**原文**
• A constant grade required to sign it.
**翻訳**
署名に必要な定数の等級。
**意味**
署名できる最低ランク。
**何をすればいいか**
`const int gradeToSign;` を定義。

---

**原文**
• A constant grade required to execute it.
**翻訳**
実行に必要な定数の等級。
**意味**
実行できる最低ランク。
**何をすればいいか**
`const int gradeToExecute;` を定義。

---

**原文**
All these attributes are private, not protected.
**翻訳**
これらの属性はすべて private、protected ではない。
**意味**
外部から直接アクセスできない。
**何をすればいいか**
必ず private に置く。

---

**原文**
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the following exceptions will be thrown if a form’s grade is out of bounds: Form::GradeTooHighException and Form::GradeTooLowException.
**翻訳**
Form の等級は Bureaucrat と同じルールに従う。範囲外なら `Form::GradeTooHighException` または `Form::GradeTooLowException` を投げる。
**意味**
1〜150 の範囲制限あり。
**何をすればいいか**
コンストラクタで grade をチェックし、例外をスロー。

---

**原文**
As before, write getters for all attributes and overload the insertion («) operator to print all the form’s information.
**翻訳**
すべての属性にゲッターを用意し、挿入演算子 `<<` をオーバーロードして Form の全情報を表示できるようにする。
**意味**
Form の情報を整形出力できる必要がある。
**何をすればいいか**
getter を作り、`std::ostream& operator<<` を実装。

---

**原文**
Also, add a beSigned() member function to the Form that takes a Bureaucrat as a parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
**翻訳**
さらに、`Form::beSigned()` メンバ関数を追加する。引数に Bureaucrat を取り、その官僚の等級が十分高ければ（必要な等級以上なら）署名状態を true にする。等級1が等級2より上であることを忘れないこと。
**意味**
署名条件をチェックする関数。
**何をすればいいか**
`void beSigned(const Bureaucrat& b);` を実装し、条件を満たせば `isSigned = true`。

---

**原文**
If the grade is too low, throw a Form::GradeTooLowException.
**翻訳**
等級が低すぎる場合は `Form::GradeTooLowException` を投げる。
**意味**
失敗時は例外処理が必須。
**何をすればいいか**
beSigned 内で grade が足りなければ例外をスロー。

---

**原文**
Then, modify the signForm() member function in the Bureaucrat class. This function must call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it will print something like: <bureaucrat> signed <form>
**翻訳**
次に Bureaucrat クラスの `signForm()` を修正する。この関数は `Form::beSigned()` を呼び、署名を試みる。成功したら以下のように出力する:
`bureaucrat signed form`
**意味**
Bureaucrat 側でも Form を扱う必要がある。
**何をすればいいか**
`signForm()` 内で beSigned を呼び、成功時にログを出す。

---

**原文**
Otherwise, it will print something like: <bureaucrat> couldn’t sign <form> because <reason>.
**翻訳**
失敗した場合は以下のように出力する:
`bureaucrat couldn’t sign form because reason`
**意味**
例外時には理由を出力。
**何をすればいいか**
catch 節で理由を `what()` から取得して表示する。

---

**原文**
Implement and submit some tests to ensure everything works as expected.
**翻訳**
すべてが期待通りに動作することを確認するテストを実装して提出する。
**意味**
テストコードも必須。
**何をすればいいか**
main.cpp で成功・失敗のテストケースを作る。















Go to homepage 🏠


SCALE FOR PROJECT CPP MODULE 05
You should evaluate 1 student in this team

Introduction
Please comply with the following rules:

- Remain polite, courteous, respectful and constructive throughout the
evaluation process. The well-being of the community depends on it.

- Identify with the student or group whose work is evaluated the possible
dysfunctions in their project. Take the time to discuss and debate the
problems that may have been identified.

- You must consider that there might be some differences in how your peers
might have understood the project's instructions and the scope of its
functionalities. Always keep an open mind and grade them as honestly as
possible. The pedagogy is useful only and only if the peer-evaluation is
done seriously.

Guidelines
- Only grade the work that was turned in the Git repository of the evaluated
student or group.

- Double-check that the Git repository belongs to the student(s). Ensure that
the project is the one expected. Also, check that 'git clone' is used in an
empty folder.

- Check carefully that no malicious aliases was used to fool you and make you
evaluate something that is not the content of the official repository.

- To avoid any surprises and if applicable, review together any scripts used
to facilitate the grading (scripts for testing or automation).

- If you have not completed the assignment you are going to evaluate, you have
to read the entire subject prior to starting the evaluation process.

- Use the available flags to report an empty repository, a non-functioning
program, a Norm error, cheating, and so forth.
In these cases, the evaluation process ends and the final grade is 0,
or -42 in case of cheating. However, except for cheating, student are
strongly encouraged to review together the work that was turned in, in order
to identify any mistakes that shouldn't be repeated in the future.

- You should never have to edit any file except the configuration file if it
exists. If you want to edit a file, take the time to explicit the reasons
with the evaluated student and make sure both of you are okay with this.

- You must also verify the absence of memory leaks. Any memory allocated on
the heap must be properly freed before the end of execution.
You are allowed to use any of the different tools available on the computer,
such as leaks, valgrind, or e_fence. In case of memory leaks, tick the
appropriate flag.

Attachments
 subject.pdf
Preliminary tests
If cheating is suspected, the evaluation stops here. Use the "Cheat" flag to report it. Take this decision calmly, wisely, and please, use this button with caution.

Prerequisites

The code must compile with c++ and the flags -Wall -Wextra -Werror
Don't forget this project has to follow the C++98 standard. Thus,
C++11 (and later) functions or containers are NOT expected.

Any of these means you must not grade the exercise in question:

A function is implemented in a header file (except for template functions).
A Makefile compiles without the required flags and/or another compiler than c++.
Any of these means that you must flag the project with "Forbidden
Function":

Use of a "C" function (*alloc, *printf, free).
Use of a function not allowed in the exercise guidelines.
Use of "using namespace <ns_name>" or the "friend" keyword.
Use of an external library, or features from versions other than C++98.
 Yes
 No
Ex00: Mommy, when I grow up, I want to be a bureaucrat!
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Bureaucrat

There is a Makefile that compiles using the appropriate flags.
There is a Bureaucrat class. It has a constant name
It has a grade that ranges from 1 (highest) to 150 (lowest).
Exceptions are thrown when trying to create a Bureaucrat with a grade
that is too high or too low.
There are accessors for the attributes
There are functions to increment / decrement the grade,
They throw exceptions when it's appropriate. Remember that incrementing a
grade 3 will give you a grade 2 (1 is the highest).
The exceptions that are used inherit from std::exception, or from
something derived from std::exception (i.e. they are catchable as
std::exception & e).
There is a << operator to ostream overload that outputs the info of the
Bureaucrat.

 Yes
 No
Ex01: Form up, maggots!
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Form

There is a Makefile that compiles using the appropriate flags. There is a Form class. It has a name, a bool that indicates whether is it signed (at the beginning it's not), a grade required to sign it, and a grade required to execute it. The names and grades are constant. All these attributes are private and not protected. The grades of the forms follow the same constraints as the Bureaucrat's (exceptions, 1 = highest 150 = lowest, and so forth). There are accessors for the attributes and a << operator to ostream overload that displays the complete state of the Form. There is a Form::beSigned() member function that works as described by the subject. There is a Bureaucrat::signForm() function that works as described by the subject.

 Yes
 No
Ex02: No, you need form 28B, not 28C...
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Forms that actually do something

There is a Makefile that compiles using the appropriate flags
There are concrete forms that are conform to the specifications of the
subject (required grades, names and actions).
They take only one parameter in their constructor, which is their target.
There is a Form::execute(Bureaucrat const & executor) method that works
as specified by the subject.
Either this method is pure and the grade checks are implemented in each
subclass, or this method performs the checks, then calls another method
in derived class that only executes the action.
Both of these techniques are valid.
There is a Bureaucrat::executeForm(Form const & form) that works as
specified by the subject.

 Yes
 No
Ex03: At least this beats coffee-making
As usual, there has to be the main function that contains enough tests to prove the program works as expected. If there isn't, do not grade this exercise. If any non-interface class is not in orthodox canonical class form, do not grade this exercise.

Intern

There is a Makefile that compiles using the appropriate flags.
There is an Intern class
It has a makeForm() function that works as specified by the subject.

 Yes
 No
Good dispatching

The makeForm() function should use some kind of array of pointers to member
functions to handle the creation of Forms.
If it's using an unclean method, like if/elseif/elseif/else branchings, or
some other ugly stuff like this, please count this as wrong.

 Yes
 No
Ratings
Don’t forget to check the flag corresponding to the defense
 Ok
 Outstanding project
 Empty work
 Incomplete work
 Invalid compilation
 Cheat
 Crash
 Concerning situation
 Leaks
 Forbidden function
Conclusion

 
 
プロジェクトCPPモジュール05のスケール
このチームの生徒を1人評価する必要があります

はじめに
以下の規則を守ってください。

- 常に礼儀正しく、礼儀正しく、敬意を払い、建設的である
評価プロセス。コミュニティの幸福はそれにかかっている。

- 作品が評価された学生またはグループと可能性を特定する
彼らのプロジェクトの機能不全。時間をかけて話し合い、議論する
特定された可能性のある問題。

- 同僚のやり方に違いがあるかもしれないことを考慮する必要があります
プロジェクトの指示とその範囲を理解していたかもしれません
機能。常にオープンマインドを保ち、できるだけ正直に採点してください
可能。教育学は、ピア評価が
真剣にやった。

ガイドライン
- 評価されたGitリポジトリで回された作品のみを採点する
学生またはグループ。

- Gitリポジトリが学生に属していることを再確認してください。必ず
プロジェクトは期待されているものです。また、「git clone」が使用されていることを確認してください。
空のフォルダ。

- 悪意のあるエイリアスがあなたをだますために使われていないことを注意深く確認してください。
公式リポジトリのコンテンツではないものを評価する。

- 驚きを避けるために、該当する場合は、使用されたスクリプトを一緒に確認してください。
グレーディングを容易にするため（テストまたは自動化のためのスクリプト）。

- 評価する課題を完了していない場合は、
評価プロセスを開始する前に、主題全体を読む。

- 利用可能なフラグを使用して、空のリポジトリ、機能していないリポジトリを報告します。
プログラム、規範エラー、不正行為など。
このような場合、評価プロセスが終了し、最終成績は0になります。
または不正行為の場合、-42。しかし、カンニングを除いて、学生は
提出された作品を一緒にレビューすることを強くお勧めします。
将来繰り返されるべきではない間違いを特定する。

- 設定ファイル以外のファイルを編集する必要はありません。
存在する。ファイルを編集したい場合は、時間をかけて理由を明確にしてください
評価された生徒と、お二人がこれで大丈夫かどうか確認します。

- また、メモリリークがないことを確認する必要があります。に割り当てられたメモリ
実行が終了する前に、ヒープを適切に解放する必要があります。
コンピュータで利用可能なさまざまなツールのいずれかを使用することが許可されています。
リーク、ヴァルグリンド、またはe_fenceなど。メモリリークが発生した場合は、
適切なフラグ。

添付ファイル
 件名.pdf
予備テスト
不正行為が疑われる場合、評価はここで終わります。「チート」フラグを使用して報告します。この決定を冷静に、賢明に、そしてこのボタンを慎重に使用してください。

前提条件

コードはc++とフラグ-Wall-Wextra-Werrorでコンパイルする必要があります
このプロジェクトはC++98標準に従わなければならないことを忘れないでください。したがって、
C++11（以降）の関数またはコンテナは期待されていません。

これらのいずれかは、問題の演習を採点してはならないことを意味します。

関数はヘッダファイルに実装されます（テンプレート関数を除く）。
Makefileは、必要なフラグやc++以外のコンパイラなしでコンパイルされます。
これらのいずれかは、プロジェクトに「禁止」とフラグを立てる必要があることを意味します。
機能」：

「C」関数の使用（*alloc、*printf、free）。
演習ガイドラインで許可されていない機能の使用。
「名前空間 <ns_name> を使用」または「friend」キーワードの使用。
外部ライブラリ、またはC++98以外のバージョンの機能の使用。
はい
いいえ
Ex00：ママ、大人になったら官僚になりたい！
いつものように、プログラムが期待どおりに機能することを証明するのに十分なテストを含むメイン関数がなければなりません。ない場合は、この演習を採点しないでください。インターフェイス以外のクラスが正統派の正規クラス形式でない場合は、この演習を採点しないでください。

官僚

適切なフラグを使用してコンパイルするMakefileがあります。
官僚階級がある。それは一定の名前を持っています
グレードは1（最高）から150（最低）までです。
グレードのある官僚を作成しようとすると、例外がスローされます。
それは高すぎるか低すぎる。
属性のアクセサがあります
グレードを増減する機能があります。
必要に応じて例外をスローします。増分することを忘れないでください
グレード3はグレード2（1が最高）になります。
使用される例外は、std::exception、または
std::exceptionから派生したもの（つまり、それらは次のようにキャッチ可能です
標準::例外とe）。
の情報を出力する ostream オーバーロードへの << 演算子があります。
官僚。

はい
いいえ
Ex01: 形をなせ、ウジ！
いつものように、プログラムが期待どおりに機能することを証明するのに十分なテストを含むメイン関数がなければなりません。ない場合は、この演習を採点しないでください。インターフェイス以外のクラスが正統派の正規クラス形式でない場合は、この演習を採点しないでください。

フォーム

適切なフラグを使用してコンパイルするMakefileがあります。フォームクラスがあります。名前、署名されているかどうかを示すブール（最初は署名されていない）、署名に必要なグレード、実行に必要なグレードがあります。名前と成績は一定です。これらの属性はすべて非公開であり、保護されていません。フォームのグレードは、官僚と同じ制約に従います（例外、1 = 最高 150 = 最低など）。属性のアクセサと、フォームの完全な状態を表示するostreamオーバーロードへの<<演算子があります。サブジェクトが説明したように機能する Form::beSigned() メンバー関数があります。サブジェクトが説明したように機能する Bureaucrat::signForm() 関数があります。

はい
いいえ
Ex02：いいえ、28Cではなく、フォーム28Bが必要です...
いつものように、プログラムが期待どおりに機能することを証明するのに十分なテストを含むメイン関数がなければなりません。ない場合は、この演習を採点しないでください。インターフェイス以外のクラスが正統派の正規クラス形式でない場合は、この演習を採点しないでください。

実際に何かをするフォーム

適切なフラグを使用してコンパイルするMakefileがあります
の仕様に適合する具体的なフォームがあります
科目（必要な成績、名前、行動）。
コンストラクタでは、ターゲットであるパラメータを1つだけ取ります。
機能するForm::execute(Bureaucrat const & executor)メソッドがあります
主題によって指定されているように。
この方法は純粋であり、成績チェックはそれぞれに実装されています
サブクラス、またはこのメソッドがチェックを実行し、別のメソッドを呼び出します
アクションのみを実行する派生クラスで。
これらのテクニックはどちらも有効です。
として機能する官僚::executeForm(Form const & form)があります。
主題によって指定される。

はい
いいえ
Ex03：少なくともこれはコーヒー作りに勝る
いつものように、プログラムが期待どおりに機能することを証明するのに十分なテストを含むメイン関数がなければなりません。ない場合は、この演習を採点しないでください。インターフェイス以外のクラスが正統派の正規クラス形式でない場合は、この演習を採点しないでください。

インターン

適切なフラグを使用してコンパイルするMakefileがあります。
インターンクラスがあります
サブジェクトが指定したとおりに機能するmakeForm（）関数があります。

はい
いいえ
良い派遣

makeForm() 関数は、メンバーへのポインタの配列を使用する必要があります。
フォームの作成を処理する機能。
if/elseif/elseif/elsese分岐のような不潔なメソッドを使用している場合、または
このような他の醜いもの、これを間違っていると数えてください。

はい
いいえ
評価
防御に対応する旗を確認することを忘れないでください
わかった
優れたプロジェクト
空の仕事
未完成の仕事
無効なコンパイル
ごまかします
クラッシュ
状況に関する
漏れ
禁止された機能
結論

 