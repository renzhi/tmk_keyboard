Renzhi Key58 keyboard firmware
==============================

DIY ergo keyboard designed and run by xp@renzhi.ca, with ideas borrowed from Key64, Ergodox and Keyboardio.

This version is hand-wired, a PCB will be designed for a next version.

## Key58 Resources
- [Renzhi's project page](http://renzhi.ca/projects/key58-keyboard/)


## Build
Move to this directory then just run `make` like:

    $ make

Note:
  Most of the codes have been copied from tmk_core/common and have been modified to target my keyboard layout. The original codes made quite a few assumptions regarding layout, I tried to inject some codes into keyboard.c, action.c, action_layer.c and keymap.c to handle my specific layout, but it's getting messy, and the changes would be hard to manage without breaking the codes for other keyboard. Therefore, I copied the necessary code into this directory and made the changes here.

## Keymap
One keymap is provided here but it is possible, and recommended, to define your favorite layout yourself if you don't the default keymap suit your needs. To define your own keymap create file named `keymap_<name>.c` and see keymap document(you can find in top README.md) and existent keymap files.

To build firmware binary hex file with a certain keymap just do `make` with `KEYMAP` option like:

    $ make KEYMAP=[default|<name>]

where <name> is the name of your own keymap. If no keymap is specified, the default keymap is built.


### 1 Default

The default keymap is the one I defined, which is quite specific for my own needs. It is defined for my daily programming habits, and I think it is optimized for Emacs and Linux.

#### 1.0 Default layer

    ,-----------------------------------,                                  ,-----------------------------------,
    | Esc |  1  |  2  |  3  |  4  |  5  |                                  |  6  |  7  |  8  |  9  |  0  |  λ  |
    |-----------------------------------|                                  |-----------------------------------|
    |  `  |  q  |  w  |  e  |  r  |  t  |                                  |  y  |  u  |  i  |  o  |  p  |Bkspc|
    |-----------------------------------|                                  |-----------------------------------|
    | Tab |  a  |  s  |  d  |  f  |  g  |                                  |  h  |  j  |  k  |  l  |  ;  |Enter|
    |-----------------------------------|                                  |-----------------------------------|
    | Caps|  z  |  x  |  c  |  v  |  b  |                                  |  n  |  m  |  ,  |  .  |  /  |Exec |
    `-----------------------------------|--------------,    ,--------------------------------------------------,
                            | Alt | Ctrl| Shift | Super|    | Fn2 | Spc | Ctrl | AltGr |
                            `--------------------------'    `--------------------------'
                                  | Fn0 |                                  | Fn1 |
                                  `-----'                                  `-----'

#### 2.0 Shift layer

This is not a real layer per se, it is documented here for completeness only.

    ,-----------------------------------,                                  ,-----------------------------------,
    | Esc |     |     |     |     |     |                                  |     |     |     |     |     |  λ  |
    |-----------------------------------|                                  |-----------------------------------|
    |  ~  |  Q  |  W  |  E  |  R  |  T  |                                  |  Y  |  U  |  I  |  O  |  P  |Bkspc|
    |-----------------------------------|                                  |-----------------------------------|
    | Tab |  A  |  S  |  D  |  F  |  G  |                                  |  H  |  J  |  K  |  L  |  :  |Enter|
    |-----------------------------------|                                  |-----------------------------------|
    | Caps|  Z  |  X  |  C  |  V  |  B  |                                  |  N  |  M  |  <  |  >  |  ?  |Exec |
    `-----------------------------------|--------------,    ,--------------------------------------------------,
                            | Alt | Ctrl| Shift | Super|    | Fn2 | Spc | Ctrl | AltGr |
                            `--------------------------'    `--------------------------'
                                  | Fn0 |                                  | Fn1 |
                                  `-----'                                  `-----'

#### 3.0 Fn layer

The Fn layer provides the function keys on the first row, and the most used symbols in programming on the second and third rows, and the navigation keys on the fourth row. On the second row, you find most of the symbols that are normally accesssed via Shift and the number row keys. The symbols are basically moved down one row to be more accessible. The third row contains symbols that are used very often, not only in programming, but in daily text editing as well.

    ,-----------------------------------,                                  ,-----------------------------------,
    | Esc | F1  | F2  | F3  | F4  | F5  |                                  | F6  | F7  | F8  | F9  | F10 |  λ  |
    |-----------------------------------|                                  |-----------------------------------|
    |     |  !  |  @  |  #  |  $  |  %  |                                  |  ^  |  &  |  *  |  '  |  |  | Del |
    |-----------------------------------|                                  |-----------------------------------|
    | Tab |  {  |  [  |  (  |  =  |  -  |                                  |  +  |  "  |  )  |  ]  |  }  |Enter|
    |-----------------------------------|                                  |-----------------------------------|
    |NLock| PgUp| Home| End | PgDn|  \  |                                  |  _  |  ◀  |  ▼  |  ▲  |  ▶  |Exec |
    `-----------------------------------|--------------,    ,--------------------------------------------------,
                            | Alt | Ctrl| Shift | Super|    | Fn2 | Spc | Ctrl | AltGr |
                            `--------------------------'    `--------------------------'
                                  | Fn0 |                                  | Fn1 |
                                  `-----'                                  `-----'



#### 4.0 AltGr layer

Alt-Gr layer tries to cover the most used math symbols, in basic math, logic, algebra, set theory, etc.

    ,-----------------------------------,                                  ,-----------------------------------,
    | Esc |  ¹  |  ²  |  ³  |  ¥  |  €  |                                  |  ⋂  |  ⋃  |  ⊂  |  ⊆  |  °  |  λ  |
    |-----------------------------------|                                  |-----------------------------------|
    |  ≈  |  ≡  |  ⇔  |  ∈  |  ∃  |  ‰  |                                  |  ⇒  |  ∧  |  ⨉  |  ∘  |  ∨  |Bkspc|
    |-----------------------------------|                                  |-----------------------------------|
    | Tab |  ∀  |  ∴  |  ∵  |  ≠  |  ¬  |                                  |  ±  |  ⊢  |  ≪  |  ≫  |  ∝  |Enter|
    |-----------------------------------|                                  |-----------------------------------|
    |NLock|  ←  |  →  |  ∙  |  ∑  |  ∏  |                                  |  ⁿ  |  √  |  ≤  |  ≥  |  ÷  |Exec |
    `-----------------------------------|--------------,    ,--------------------------------------------------,
                            | Alt | Ctrl| Shift | Super|    | Fn2 | Spc | Ctrl | AltGr |
                            `--------------------------'    `--------------------------'
                                  | Fn0 |                                  | Fn1 |
                                  `-----'                                  `-----'

TODO: Need to refine this layer, this is not optimal. This layer is kind of subjective.

Notes:
1) Some of the most used symbols that may be represented with two symbols are mapped here, such as ':=' '::', etc.
2) The symbol on the '0' key is ° (degree sign)
3) The symbol on the 'o' key is ∘ (function composition)
4) The symbol on the 'm' key is → (function arrow, also used to mean "implies")
5) The symbol on the 'g' key is ¬ (not, negation)
6) The symbol on the 'k' key is ⊢ (turnstile, it means yields, proves, satisfies, entails, infers, or derives)
7) The symbol on the 'b' key is ∏ (product)

I need to type in French from time to time, so do people who need to work in a multi-cultural environment. Therefore, access to accentuated characters is quite important. However, I don't use French (or other variants of French language layout) keyboard on a daily basis, I can't remember the keymap layout. It's easier for me to use a combination of keys to enter accentuated characters, which, admittedly, is not an optimal way to work if you daily working language is French or another language that requires constant use of accentuated characters. In that case, it would be better to define a new keymap. 

To input accentuated characters, use a combination of keys as follow, which is an easier way to remember.

Alt-Gr + ' + a = 
Alt-Gr + ' + e = 
Alt-Gr + ' + i = 
Alt-Gr + ' + o = 
Alt-Gr + ' + u = 

Alt-Gr + ` + a = 
Alt-Gr + ` + e = 
Alt-Gr + ` + i = 
Alt-Gr + ` + o = 
Alt-Gr + ` + u = 

Alt-Gr + ^ + a = 
Alt-Gr + ^ + e = 
Alt-Gr + ^ + i = 
Alt-Gr + ^ + o = 
Alt-Gr + ^ + u = 

Alt-Gr + " + a = 
Alt-Gr + " + e = 
Alt-Gr + " + i = 
Alt-Gr + " + o = 
Alt-Gr + " + u = 

// TODO: This layer is not implemented yet

#### 5.0 Numlock layer

// TODO: This layer is not implemented yet

// TODO: Implement the lambda key

#### 6.0 Mouse Key layer

This layer contains mouse keys and buttons, and system control keys, such as volume control, screen brightness control, sleep/hibernate, etc.

// TODO: This layer is not implemented yet
