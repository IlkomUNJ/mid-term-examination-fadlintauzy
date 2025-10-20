Objectives
1. Analyze and finding correct window size in identifying a segment.
2. Report all fitting of appropriate window pattern for identifying a segment.
3. Develop automated algorithm based on the previous findings to detect all potential candidates of a segment


Answer 
1. Untuk mencari window yang pas untuk menentuka line segment pertama tama kita harus mengetahui width dari lain tersebut dari segi pixel karena semakin besar ukuran linenya semakin dibutuhkan window yang lebih besar untuk menentukan insersectionnya karna width dari linenya merupakan 4 "pen.setWidth(4); " jadi kita harus mencari ukuran window yang dapat menampung 2 line dengan widthnya masing masing 4 dan dapat membentuk "X" yang menandakan intersection jadi yang paling benar menurutnya saya adalah window 10 x 10 karna memiliki dimensi yang cukup luas dan dapat memvisualisasikan step by step bagaimana kedua garis tersebut bertemu dari yang awalnya belum bertemu.

2. untuk window yang cukup dalam memvisualisasikan segment menurut saya dari windows 8 x 8 tetapi hanya menampilkan tempat bertemunya saja, untuk ukuran window   seperti 9x9 dst,sudah dapat memvisualisasikan secara baik bahkan dari proses menuju pertemuan kedua garis tersebut tetapi untuk akhir saya memilih window 10x10 agar lebih jelas lagi proses dari sebelum bertemu hingga bertemu dan menjauh lagi.




