# ЗВІТ

про виконання лабораторної роботи № 2.0
«Системи контролю версій»
з дисципліни «Алгоритмізація та програмування»
студента групи КН-2630б
**Турків Остап Миколайович**

---

## Умова завдання

1. (1 бал) Створити локальний git-репозиторій. Додати до нього папку проекту, створеного при виконанні Лабораторної роботи № 2.1. Зробити кілька змін у проекті, кожну зміну фіксувати окремим комітом. Продемонструвати відкат до попереднього коміту.
2. (1 бал) Створити нову гілку в локальному git-репозиторії та кілька комітів в обох гілках (старій і новій). Продемонструвати перемикання між гілками. Продемонструвати відкати до попередніх комітів у кожній гілці.
3. (1 бал) Скопіювати локальний git-репозиторій у віддалений. Внести зміни до локального репозиторію. Скопіювати внесені зміни у віддалений репозиторій.
4. (1 бал) Внести зміни до локального репозиторію, яких немає у віддаленому. Відновити локальний репозиторій з віддаленого.
5. (1 бал) Злити гілки. Продемонструвати злиття гілок локального репозиторію, а також локального та віддаленого.

## Відповідь

Нижче наведено реальний вивід консолі git (Git Bash) під час виконання кожного кроку. Рядок, що починається з `$`, — це введена команда, під ним — відповідь git.

Віддалений репозиторій: <https://github.com/ostapturkiv317-creator/AP_labs>

### 1. Локальний репозиторій, коміти, відкат

`git init` створює локальний репозиторій, `git add` додає файли до індексу, `git commit` фіксує зміни. Відкат до попереднього коміту виконано командою `git reset --hard HEAD~1`: останній коміт скасовано, вміст файлу `1.txt` повернувся до попереднього стану.

```text
$ git init
Initialized empty Git repository in .../AP_labs/.git/

$ git branch -M master

$ git config user.name
Ostap Turkiv

$ git add . ':!Lab_5_0' ':!Lab_2_0'

$ git commit -q -m 'Labs 1.1-5.5 (variant 33): programs and reports' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'

$ git log --oneline
71e42f4 Labs 1.1-5.5 (variant 33): programs and reports

$ git add Lab_2_0/1.txt

$ git commit -m 'Lab 2.0: add 1.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master 45fd7bf] Lab 2.0: add 1.txt
 1 file changed, 1 insertion(+)
 create mode 100644 Lab_2_0/1.txt

$ git commit -am 'Lab 2.0: change 1.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master ba9fa2a] Lab 2.0: change 1.txt
 1 file changed, 1 insertion(+), 1 deletion(-)

$ git log --oneline
ba9fa2a Lab 2.0: change 1.txt
45fd7bf Lab 2.0: add 1.txt
71e42f4 Labs 1.1-5.5 (variant 33): programs and reports

$ cat Lab_2_0/1.txt
1 - changed

$ git reset --hard HEAD~1
HEAD is now at 45fd7bf Lab 2.0: add 1.txt

$ git log --oneline
45fd7bf Lab 2.0: add 1.txt
71e42f4 Labs 1.1-5.5 (variant 33): programs and reports

$ cat Lab_2_0/1.txt
1
```

### 2. Нова гілка, коміти в обох гілках, перемикання, відкати

`git checkout -b branch_02` створює гілку `branch_02` і перемикається на неї, `git checkout master` повертає на головну гілку. У кожній гілці зроблено коміти та відкат останнього коміту.

```text
$ git checkout -b branch_02
Switched to a new branch 'branch_02'

$ git rm -q Lab_2_0/1.txt

$ git add Lab_2_0/2.txt

$ git commit -m 'branch_02: replace 1.txt with 2.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[branch_02 d4d3d49] branch_02: replace 1.txt with 2.txt
 2 files changed, 1 insertion(+), 1 deletion(-)
 delete mode 100644 Lab_2_0/1.txt
 create mode 100644 Lab_2_0/2.txt

$ git commit -am 'branch_02: change 2.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[branch_02 51e4f3e] branch_02: change 2.txt
 1 file changed, 1 insertion(+), 1 deletion(-)

$ git log --oneline -3
51e4f3e branch_02: change 2.txt
d4d3d49 branch_02: replace 1.txt with 2.txt
45fd7bf Lab 2.0: add 1.txt

$ git reset --hard HEAD~1
HEAD is now at d4d3d49 branch_02: replace 1.txt with 2.txt

$ cat Lab_2_0/2.txt
2

$ git checkout master
Switched to branch 'master'

$ ls Lab_2_0
1.txt

$ git add Lab_2_0/3.txt

$ git commit -m 'master: add 3.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master b531801] master: add 3.txt
 1 file changed, 1 insertion(+)
 create mode 100644 Lab_2_0/3.txt

$ git commit -am 'master: change 3.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master 6f13ca2] master: change 3.txt
 1 file changed, 1 insertion(+), 1 deletion(-)

$ git reset --hard HEAD~1
HEAD is now at b531801 master: add 3.txt

$ cat Lab_2_0/3.txt
3

$ git log --oneline --graph --all
* b531801 master: add 3.txt
| * d4d3d49 branch_02: replace 1.txt with 2.txt
|/  
* 45fd7bf Lab 2.0: add 1.txt
* 71e42f4 Labs 1.1-5.5 (variant 33): programs and reports
```

### 3. Копіювання у віддалений репозиторій

`git remote add origin` задає адресу віддаленого репозиторію, `git push -u origin <гілка>` відправляє гілку на GitHub.

```text
$ git remote add origin https://github.com/ostapturkiv317-creator/AP_labs.git

$ git remote -v
origin	https://github.com/ostapturkiv317-creator/AP_labs.git (fetch)
origin	https://github.com/ostapturkiv317-creator/AP_labs.git (push)

$ git push -u origin master
To https://github.com/ostapturkiv317-creator/AP_labs.git
 * [new branch]      master -> master
branch 'master' set up to track 'origin/master'.

$ git push -u origin branch_02
remote: 
remote: Create a pull request for 'branch_02' on GitHub by visiting:        
remote:      https://github.com/ostapturkiv317-creator/AP_labs/pull/new/branch_02        
remote: 
To https://github.com/ostapturkiv317-creator/AP_labs.git
 * [new branch]      branch_02 -> branch_02
branch 'branch_02' set up to track 'origin/branch_02'.
$ git commit -am 'master: update 3.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master 337c39e] master: update 3.txt
 1 file changed, 1 insertion(+), 1 deletion(-)

$ git push
To https://github.com/ostapturkiv317-creator/AP_labs.git
   b531801..337c39e  master -> master

$ git status -sb
## master...origin/master
?? Lab_2_0/README.md
?? Lab_5_0/
```

### 4. Зміни, яких немає у віддаленому репозиторії; відновлення з віддаленого

Зроблено локальний коміт, який не відправлявся на GitHub. Потім `git fetch` завантажив стан віддаленого репозиторію, а `git reset --hard origin/master` відновив локальну гілку до стану віддаленої. `git pull` підтвердив, що локальна гілка збігається з віддаленою.

```text
$ git add Lab_2_0/local.txt

$ git commit -m 'local only: add local.txt' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
[master 595400c] local only: add local.txt
 1 file changed, 1 insertion(+)
 create mode 100644 Lab_2_0/local.txt

$ git status -sb
## master...origin/master [ahead 1]
?? Lab_2_0/README.md
?? Lab_5_0/

$ git fetch origin

$ git reset --hard origin/master
HEAD is now at 337c39e master: update 3.txt

$ git pull
Already up to date.

$ git status -sb
## master...origin/master
?? Lab_2_0/README.md
?? Lab_5_0/

$ ls Lab_2_0
1.txt
3.txt
README.md
```

### 5. Злиття гілок

Гілку `branch_02` злито в `master` локально (`git merge`), після чого результат відправлено у віддалений репозиторій (`git push`).

```text
$ git branch -a
  branch_02
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/branch_02
  remotes/origin/master

$ git merge branch_02 -m 'Merge branch branch_02 into master' -m 'Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>'
Merge made by the 'ort' strategy.
 Lab_2_0/1.txt | 1 -
 Lab_2_0/2.txt | 1 +
 2 files changed, 1 insertion(+), 1 deletion(-)
 delete mode 100644 Lab_2_0/1.txt
 create mode 100644 Lab_2_0/2.txt

$ ls Lab_2_0
2.txt
3.txt
README.md

$ git push origin master
To https://github.com/ostapturkiv317-creator/AP_labs.git
   337c39e..cec0b19  master -> master

$ git log --oneline --graph --all
*   cec0b19 Merge branch branch_02 into master
|\  
| * d4d3d49 branch_02: replace 1.txt with 2.txt
* | 337c39e master: update 3.txt
* | b531801 master: add 3.txt
|/  
* 45fd7bf Lab 2.0: add 1.txt
* 71e42f4 Labs 1.1-5.5 (variant 33): programs and reports
```

## Висновки

Я навчився працювати з системою контролю версій git: створювати локальний репозиторій, фіксувати зміни комітами, відкочуватися до попередніх комітів, створювати гілки та перемикатися між ними. Також навчився пов'язувати локальний репозиторій з віддаленим на GitHub, відправляти зміни (`push`), завантажувати їх (`fetch`, `pull`), відновлювати локальний стан з віддаленого та зливати гілки (`merge`).
