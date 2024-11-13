<p>
    Цель:<br>
    # Рассмотреть возможность использования одночастотных приёмников спутниковых радионавигационных систем (СРНС) для получения информации с целью оперативной коррекции её модели.<br>
    # Установить и настроить программные обеспечения для обработки и сортировки данных.<br>
    # Получить данные с одночастотного приемника СРНС.<br>
    # Описать формат файлов RINEX.<br>
    # Разработать программу, которая считывает файлы в формате Rinex и сортирует псевдодальности (ПД) от времени (эпохи) по каждому навигационному спутнику.<br>
    # Получить результаты.<br>
    Skills:<br>
    # Спутниковые радионаввигационные системы.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Task:</strong><br>
    Методика коррекции ионосферы по данному приёмнику СРНС.<br>
    # Спутниковые радионаввигационные системы.<br>
    <strong>Decision:</strong><br>
    Рассмотрим возможность оценки вклада ионосферы в измерения псевдодальности (ПД) с помощью одночастотного приёмника ГЛОНАСС/GPS. Для этого будем считать, что координаты приемника x, y, z неизменны и известны с высокой точностью. ПД от i-го навигационного спутника (НС) с координатами xi, yi, zi определим как измеренную в свободном пространстве дальность D'i=сτ'i, отличающуюся от геометрической дальности (ГД) Di на неизвестную величину ρ:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:637/44;" src="/media/formula4.1.png" width="637" height="44">
</figure>
<p>
    D'i=сτ'i определяется по разности моментов приема и передачи навигационного сигнала между временными шкалами НС и приемника. Если точность шкалы НС с учетом её коррекции достаточна для определения момента излучения, то из-за нестабильности шкалы приемника необходимо учитывать её мгновенный сдвиг относительно шкалы НС на неизвестную величину t' и ρ=ct'. В многоканальных одночастотных приемниках t' не зависит от i и значение ρ одинаково для всех НС в данный момент времени [6].<br>
    В реальных условиях результаты измерения ПД D''i отличаются от значения D'i из формулы (4.1) из-за влияния различных факторов на распространение навигационных сигналов. Основные ошибки, возникающие при этом, вызваны запаздыванием сигнала в ионосфере и тропосфере , а также погрешностями определения эфемерид . Другие ошибки хорошо компенсируются алгоритмами обработки сигналов. Например, влияние многолучевости значительно уменьшается усреднением данных на интервале 30 с и более, а релятивистские эффекты устраняются коррекцией навигационного сигнала [6].<br>
    Таким образом, ошибка измерения ПД в основном определяется следующими составляющими:
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:620/30;" src="/media/formula4.2.png" width="620" height="30">
</figure>
<p>
    Отсюда можно найти вклад ионосферы в ошибку измерения ПД для i-го НС:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:625/29;" src="/media/formula4.3.png" width="625" height="29">
</figure>
<p>
    Величина ρ в формуле (4.3) зависит от расхождения шкал времени НС и приемника и меняется в очень широких пределах.&nbsp;<br>
    При решении навигационной задачи относительно времени, шкала приемника может быть привязана к шкале НС, но найденная при этом величина ρ' будет характеризовать эффективное значение с учетом других ошибок определения ПД, и в этом случае будет иметь смысл отклонения от некоторого среднего значения для всех НС, участвующих в навигационном решении [6].<br>
    Для устранения влияния нестабильности временнόй шкалы приемника построим разность ошибок ионосферы для i-го и j-го НС в один момент времени:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:623/28;" src="/media/formula4.4.png" width="623" height="28">
</figure>
<p>
    Как видно, точность определения зависит от погрешностей определения эфемерид выбранных НС и разностей тропосферных задержек сигналов от них. обычно составляет единицы метров. Если из созвездия выбирать НС со «свежими» эфемеридами, то эта погрешность уменьшится до ~1 м. Применение постобработки и использование уточнённых эфемерид дает погрешность значительно меньше 1 м. Если предположить, что ошибки для двух НС независимы, а их величины примерно одинаковы, то общая ошибка из-за погрешностей задания эфемерид [6]:
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:628/28;" src="/media/formula4.5.png" width="628" height="28">
</figure>
<p>
    Задержка в тропосфере приводит к ошибке в измерении ПД, которая хорошо компенсируется простыми моделями тропосферы. В нормальных условиях в тропосфере для углов места β &gt; 5º и достижения погрешности после коррекции &lt; 0.5 м можно воспользоваться формулой:
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:626/52;" src="/media/formula4.6.png" width="626" height="52">
</figure>
<p>
    Здесь - задержка сигнала в тропосфере для зенитных НС, равная ~7 нс, что соответствует пути 2.1 м. Для увеличения точности коррекции можно применить модель Саастамойнена.<br>
    Таким образом, общая величина ошибки определения в благоприятных условиях составляет ~1÷2 м и вариации ионосферной задержки величиной ~10 и более метров могут быть определены одночастотным приемником ГНСС.<br>
    <strong>Task:</strong><br>
    Получение данных с одночастотного приемника СРНС.<br>
    # Спутниковые радионаввигационные системы.<br>
    <strong>Decision:</strong><br>
    Для проверки способа определения вариации ионосферной задержки 19 мая 2015 года провел обработку данных измерения навигационных сигналов от нескольких НС. Для измерений использовался 20 канальный одночастотный приемник BU-353 фирмы GlobalSat. Этот приемник предназначен для ГНСС GPS, работает на частоте L1 по C/A коду и имеет высокую чувствительность 159 дБм. Данные о псевдодальностях доступны только при использовании бинарного протокола, поэтому при наблюдениях применялась программа SirfTech версии 2.20 и данные записывались в RINEX файл. Описание программы SirfTech можно увидеть прил. 5.&nbsp;<br>
    <strong>Task:</strong><br>
    Алгоритм обработки данных.<br>
    # Спутниковые радионаввигационные системы.<br>
    <strong>Decision:</strong><br>
    Большая часть программного обеспечения обработки данных GPS использует определенный набор наблюдений:<br>
    - фазовые измерения на одной или двух несущих частотах;<br>
    - измерения псевдодальности (кода), которые соответствуют разности между временем получения и временем передачи отдельных сигналов спутника;<br>
    - время наблюдения считывается с часов приемника в момент измерения фазы несущей и/или кода.<br>
    При обработке необходимыми являются: фаза, код и время, определение которых дано выше, и некоторая информация относительно станции, такая как название станции, высота антенны и другие [5].<br>
    <strong>Task:</strong><br>
    Описание формата RINEX.<br>
    # Спутниковые радионаввигационные системы.<br>
    <strong>Decision:</strong><br>
    Для решении навигационной задачи исходными данными являются файлы в формате RINEX - независимый от приемника формат для обмена данными СРНС. RINEX - формат состоит из трех типов ASCII файлов - файлы метеорологических параметров (meteorological data file), файлы результатов измерений (observation data file), файлы с оперативной эфемеридной информацией, полученные в составе навигационного сообщения (navigation message file) [5].<br>
    Файлы имеют различную длину, максимальное значение равно 80 символам в строке (табл. 2). Каждый файл содержит секцию заголовков и секцию данных. Файл навигационного сообщения располагается независимо, в то время как файлы измерений и метеорологических данных должны быть созданы для каждого используемого при наблюдениях пункта [5].&nbsp;<br>
    Таблица 2. Общая структура формата RINEX:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:639/141;" src="/media/table2.png" width="639" height="141">
</figure>
<p>
    Результаты измерений располагаются по эпохам. Каждой эпохе наблюдения соответствует структура, представленная на табл. 3 (количество и порядок расположения результатов различных типов измерений указывается в заголовке файла в строке "# / TYPES OF OBSERV", например, «7 LI L2C1 PI P2»), где у у mm dd hh mm sec момент приема сигнала по часам потребителя (tp); № - номера спутников, результаты наблюдений которых в соответствующем порядке записываются для каждой эпохи (при совместной обработке наблюдений ИСЗ обеих систем либо резервируются номера с 1 по 32 для спутников GPS и с 33 по 64 для спутников ГЛОНАСС, либо вводятся дополнительные признаки G и R); ИСЗ фаза L1 - псевдодальность, измеренная по фазе несущей на частоте L1; ИСЗ фаза L2 - псевдодальность, измеренная по фазе несущей на частоте L2; ИСЗ код С1 - псевдодальность, измеренная по С/А-коду на частоте L1; ИСЗ код Р1 - псевдодальность, измеренная по Р-коду на частоте L1; ИСЗ код Р2 - псевдодальность, измеренная по Р-коду на частоте L2 [2].<br>
    Таблица 3. Результаты СРНС-измерений на одну эпоху&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:532/93;" src="/media/table3.png" width="532" height="93">
</figure>
<p>
    Оперативная эфемеридная информация, полученная в составе навигационного сообщения, сгруппирована по номерам ИСЗ. Фрагменты файла измерений в формате RINEX представлены в прил. 2 [5].<br>
    GPS наблюдения включают в себя три основных понятия, которым необходимо дать определение: время, фаза и псевдодальность. Время измерений - это время приемника в момент приема сигналов. Оно одинаково для измерений фазы и псевдодальности и одинаково для всех наблюдаемых спутников в данную эпоху. Время выражается в единицах GPS-времени (не в мировом времени, UTC).<br>
    Псевдодальность (ПД) - это расстояние от приемной антенны до антенны спутника, включая сдвиги шкалы времени приемника и спутниковых часов (и другие сдвиги, такие как атмосферные задержки). Псевдодальность отражает реальное поведение часов приемника и передатчика. Псевдодальность указывается в единицах длины - метрах.<br>
    Фаза - это фаза несущей, измеренная в целых циклах. Измеряемое количество полуциклов квадратурными приемниками должно быть конвертировано в целые циклы и соответственно изменено значение длины волны в заголовке файла (только для GPS) [5].<br>
    Изменения фазы положительно коррелированны с изменениями дальности (негативный эффект Доплера). Фазовые наблюдения между эпохами должны быть скорректированы включением целого числа циклов. Фазовые наблюдения не будут содержать никаких систематических сдвигов от намеренных сдвигов опорных генераторов.<br>
    Данные всех измерений не скорректированы на внешние эффекты, такие как атмосферная рефракция, сдвиг часов спутникового передатчика и другие. Если приемник или программа конвертера производят измерения сдвига часов приемника в реальном времени dT(изм), то соответственно три параметра (фаза, псевдодальность, эпоха) должны быть исправлены. Знак доплеровского сдвига частоты определяется как обычно - положительный знак при приближении спутника [5].<br>
    <strong>Task:</strong><br>
    Для дальнейшей обработки и сортировки данных мною была написана программа на языке С++, которая считывает файлы в RINEX формате и сортирует псевдодальности по каждому НС, что упрощает дальнейшую обработку. Для основной обработки данных по формуле 4.4 выполнялись вычисления с помощью редактора EXCEL.<br>
    <strong>Task:</strong><br>
    Алгоритм.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    Из текстового файла вывести всю информацию до END OF HEADER в out.txt.<br>
    Вывести следующую строку после END OF HEADER - время и название спутников.<br>
    Вывести количество спутников и названия спутников в строке.<br>
    Вывести название спутников по буквам, то есть создаем динамический массив с указателем.<br>
    Вывести вторую строку название спутников.<br>
    Вывести буквы спутников в столбец.<br>
    Вывести по буквам и по цифрам. если увидим пробел, тогда операция не должна выполняться.<br>
    Вывести все спутники в столбец.<br>
    Вывести псевдодальности для одной/первой эпохи (время - 0:0).<br>
    Вывести названия спутников для первой эпохи.<br>
    Вывести псевдодальности для каждого спутника.<br>
    Вывести название спутника и расстояние (дальность) спутника. первая строка - для первой эпохи, вторая строка - для второй эпохи<br>
    Вывести для всех эпох данные спутников.<br>
    Вывести на экран данные для двух спутников.<br>
    Вывести данные именно для одного спутника, например первого.<br>
    <strong>Task:</strong><br>
    Вывести названия спутников из файла для первой минуты.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat IRKL1119.txt<br>
    2.11 OBSERVATION DATA M (MIXED) RINEX VERSION / TYPE<br>
    ...<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER<br>
    11 11 19 0 0 0.0000000 0 18G 1G28R22G1R12G 7G 3G 6R 6R24R 5G26-0.000381360<br>
    &nbsp;&nbsp;&nbsp;&nbsp;G11G16R13R14G 8R23<br>
    23815384.399 23815383.399 125150709.498 3 3673.062 23.000<br>
    ...<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    int countSputnik;<br>
    in &gt;&gt; countSputnik;<br>
    cout&lt;&lt; countSputnik&lt;&lt;endl ;<br>
    getline(in,name);<br>
    // cout&lt;&lt; name &lt;&lt;endl;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++)<br>
    {<br>
    &nbsp;&nbsp;if(name[i] == '-')<br>
    &nbsp;&nbsp;break;<br>
    &nbsp;&nbsp;if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp; index++;<br>
    &nbsp;&nbsp; if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tempName="";<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if (name[i] != ' '){<br>
    &nbsp;&nbsp; tempName = tempName + name[i];<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index != countSputnik -1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    &nbsp;&nbsp;getline(in,name);<br>
    &nbsp;&nbsp;for(int i=0; i&lt;name.size(); i++){<br>
    &nbsp;&nbsp; if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if (name[i] != ' '){<br>
    &nbsp;&nbsp; tempName = tempName + name[i];<br>
    &nbsp;&nbsp;}<br>
    }<br>
    }<br>
    for(int i=0; i&lt;countSputnik; i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    /*<br>
    delete [] Sputnik;<br>
    // ���������� ��������������� ��� ����� �����<br>
    double *information = new double [countSputnik];<br>
    for(int i=0; i&lt;countSputnik; i++){<br>
    in &gt;&gt; information[i];<br>
    getline (in,name);<br>
    getline (in,name);<br>
    }<br>
    for(int i=0; i&lt;countSputnik; i++){<br>
    out &lt;&lt; information[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    /*<br>
    double *information = new double [countSputnik];<br>
    double information1;<br>
    for(int i=0; i&lt;countSputnik; i++){<br>
    in &gt;&gt; information1;<br>
    in &gt;&gt; information[i];<br>
    getline (in,name);<br>
    getline (in,name);<br>
    }<br>
    for(int i=0; i&lt;countSputnik; i++){<br>
    cout &lt;&lt; information[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    G1<br>
    G28<br>
    R22<br>
    G1<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G8<br>
    <strong>Task:</strong><br>
    Читаем Каждую Букву И Цифру После строки названия спутников для первой минуты.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat igs19236-1.txt<br>
    #cP2016 11 19 0 0 0.00000000 96 ORBIT IGb08 HLM IGS<br>
    ...<br>
    * 2016 11 19 0 0 0.00000000<br>
    PG01 -20514.995126 -11031.142105 12884.404415 40.929190 7 8 4 99&nbsp;<br>
    PG02 12690.844622 22403.534044 7723.409365 523.430781 9 7 9 125&nbsp;<br>
    ...<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("igs19236-1.txt");<br>
    ofstream out ("out.txt");&nbsp;<br>
    // ���������� �� ORB:CMB CLK:CMB<br>
    string stroka;<br>
    for (int i=0; i&lt;22; i++)<br>
    {<br>
    &nbsp;&nbsp;getline (in,stroka);<br>
    }<br>
    // ��������� �����<br>
    string epoha;<br>
    getline(in,epoha);<br>
    //out &lt;&lt; epoha &lt;&lt; endl;<br>
    /*char zvezda;<br>
    int data;<br>
    int vremia;<br>
    double sostoianie;<br>
    in &gt;&gt; zvezda;<br>
    in &gt;&gt; data;<br>
    in &gt;&gt; data;<br>
    in &gt;&gt; data;<br>
    in &gt;&gt; vremia;<br>
    in &gt;&gt; vremia;<br>
    in &gt;&gt; sostoianie;<br>
    //out &lt;&lt; sostoianie;*/<br>
    // ��������� ������� ���� ��������� � �� ����������<br>
    /*<br>
    string position; // ��� ���� ������<br>
    getline (in,position);<br>
    out &lt;&lt; position &lt;&lt; endl;<br>
    */<br>
    /*//������ ������� +<br>
    string sputnik; //������� ��������<br>
    string e; // EOF � * 2016 11 19<br>
    string x;<br>
    string y;<br>
    string z;<br>
    string signali; //������ �������<br>
    for (int j=0; j&lt;96; j++){ //��� ���� ��������� � ��� ���� ����<br>
    &nbsp;&nbsp;for (int i=0; i&lt;32; i++){ //��� ���� ��������� � ��� ����� �����<br>
    &nbsp;&nbsp; in &gt;&gt; sputnik &gt;&gt; x &gt;&gt; y &gt;&gt; z;<br>
    &nbsp;&nbsp; getline (in, signali);<br>
    &nbsp;&nbsp; out &lt;&lt; sputnik &lt;&lt; " " &lt;&lt; x &lt;&lt; " " &lt;&lt; y &lt;&lt; " " &lt;&lt; z &lt;&lt; " " &lt;&lt; endl;<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;getline (in, e); // ��������� EOF � * 2016 11 19<br>
    }*/<br>
    /* //������ ������� -<br>
    int b;<br>
    //getline (in,position);<br>
    //out &lt;&lt; position &lt;&lt; endl;<br>
    <br>
    string *info = new string [b];<br>
    for (int i=0; i&lt;b; i++)<br>
    {<br>
    &nbsp;&nbsp;info[i]="";<br>
    }<br>
    int index=-1;<br>
    for(int i=0; i&lt; position.size(); i++) {<br>
    &nbsp;&nbsp;if(position[i] &gt;= 'A' &amp;&amp; position[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp; index++;<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if (position[i] !=' '){<br>
    &nbsp;&nbsp; info[index] = info[index] + position[i];<br>
    &nbsp;&nbsp;}<br>
    }<br>
    for(int i=0; i&lt;b; i++)<br>
    {<br>
    &nbsp;&nbsp;out &lt;&lt; " " &lt;&lt; info[i] &lt;&lt; " " &lt;&lt; endl;<br>
    }<br>
    delete [] info;<br>
    */<br>
    /*<br>
    double *information = new double [b];<br>
    <br>
    for(int i=0; i&lt;b; i++)<br>
    {<br>
    &nbsp;&nbsp;in &gt;&gt; information[i];<br>
    &nbsp;&nbsp;//getline (in,position);<br>
    &nbsp;&nbsp;//getline (in,position);<br>
    }<br>
    for(int i=0; i&lt;b; i++){<br>
    &nbsp;&nbsp;out &lt;&lt; information[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    string position; // ��� ���� ������<br>
    getline (in,position); // ����������� ��� ������ �������<br>
    //out &lt;&lt; position &lt;&lt; endl;<br>
    // ������� ������ ������� ���� ������<br>
    vector &lt;string&gt; infa; // ������� ������ ������ � ����� ������� �����<br>
    int index=-1; // ��������� ��������<br>
    string infaPosition = ""; // ������ ������� ��� ������ ��������<br>
    for(int i=0; i&lt; position.size(); i++) { // ��� ������ ���� ������� ����� �������<br>
    &nbsp;&nbsp;if(position[i] &gt;= 'A' &amp;&amp; position[i] &lt;= 'Z') { // 1 ���� ��������� �����<br>
    &nbsp;&nbsp; index++; // �������� ���������<br>
    &nbsp;&nbsp; /*if(infaPosition != "") { // ����<br>
    &nbsp;&nbsp;&nbsp;&nbsp;infa.push_back(infaPosition);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;infaPosition="";<br>
    &nbsp;&nbsp; } */<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;/*if (position[i] != ' '){<br>
    &nbsp;&nbsp; infaPosition = infaPosition + position[i];<br>
    &nbsp;&nbsp;}*/<br>
    &nbsp;&nbsp;out &lt;&lt; position[i] &lt;&lt; endl; // ������� � ������ ������ �������<br>
    }<br>
    /* string a;<br>
    getline (in,a);<br>
    out &lt;&lt; a &lt;&lt; endl;&nbsp;<br>
    */<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat out.txt<br>
    P<br>
    G<br>
    0<br>
    1<br>
    -<br>
    2<br>
    0<br>
    5<br>
    1<br>
    4<br>
    .<br>
    9<br>
    9<br>
    5<br>
    1<br>
    2<br>
    6<br>
    -<br>
    1<br>
    1<br>
    0<br>
    3<br>
    1<br>
    .<br>
    1<br>
    4<br>
    2<br>
    1<br>
    0<br>
    5<br>
    1<br>
    2<br>
    8<br>
    8<br>
    4<br>
    .<br>
    4<br>
    0<br>
    4<br>
    4<br>
    1<br>
    5<br>
    4<br>
    0<br>
    .<br>
    9<br>
    2<br>
    9<br>
    1<br>
    9<br>
    0<br>
    7<br>
    8<br>
    4<br>
    9<br>
    9<br>
    <strong>Task:</strong><br>
    Мы Выводим Данные Спутников G16 В Текстовый Файл для каждой эпохи.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat IRKL1119.txt<br>
    ...<br>
    &nbsp;&nbsp;&nbsp;&nbsp;G11G16R13R14G 8R23<br>
    23815384.399 23815383.399 125150709.498 3 3673.062 23.000<br>
    23815389.819 97520038.895 3 2862.131 23.000<br>
    23418101.271 23418101.711 123062972.555 4 2734.873 26.000<br>
    23418102.171 95893253.756 4 2131.058 26.000<br>
    ...<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;cmath&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    int countSputnik;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(53);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = "";<br>
    for(int i=0; i&lt;2880; i++) {<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    /*out &lt;&lt; countSputnik &lt;&lt; endl; */<br>
    getline(in,name);<br>
    allSputnik.resize(0);<br>
    index=-1; //��������� ��������<br>
    tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    /*<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost=0;<br>
    /*<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    */<br>
    string b = "";<br>
    getline (in, b);<br>
    a ="";<br>
    if(b.size()&gt;=30){<br>
    a=b.substr(17,13);<br>
    }<br>
    int tochka=-1;<br>
    int chislo=0;<br>
    for (int i=0; i&lt;a.size(); i++){<br>
    &nbsp;&nbsp;if (a[i]&gt;='0' &amp;&amp; a[i]&lt;='9'){<br>
    &nbsp;&nbsp; dalnost = dalnost *10 + (a[i]-'0');<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;else {<br>
    &nbsp;&nbsp; if(a[i]== '.') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tochka=i;<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(tochka != -1){<br>
    &nbsp;&nbsp;chislo = a.size()-1 - tochka;<br>
    &nbsp;&nbsp;chislo = (int) pow(10, (double)chislo);<br>
    &nbsp;&nbsp;dalnost=dalnost/chislo;<br>
    }<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    }<br>
    // out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++){<br>
    out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][0] &lt;&lt; setw(14) &lt;&lt; info[i][1] &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    ...<br>
    23418101.711<br>
    23402498.509<br>
    23386912.128<br>
    23371345.657<br>
    23355798.957<br>
    ...<br>
    <strong>Task:</strong><br>
    Выводим список спутников и их псевдоальность для первой эпохи.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    int countSputnik;<br>
    in &gt;&gt; countSputnik;<br>
    //out&lt;&lt; countSputnik&lt;&lt;endl ;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(100);<br>
    getline(in,name);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ���������<br>
    int index=-1; //��������� ��������<br>
    string tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    //out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost;<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    getline (in,name);<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setprecision(12) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    G1 G28 R22 G19 R12 G7 G3 G6 R6 R24 R5 G26 G11 G16 R13 R14 G9 R23&nbsp;<br>
    23815383.399 23418101.711 20126478.966 20576502.049 20850572.801 20361179.631 22177242.661 23871188.467 23896969.354 22949017.462 23330231.749 23194678.499 21898256.651 24811902.872 19151353.321 21666798.485 20650945.821 19472152.449 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    <strong>Task:</strong><br>
    Выводим количество спутников, название спутников и пссевдодальность для каждого спутника за первые 15 минут.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    int countSputnik;<br>
    in &gt;&gt; countSputnik;<br>
    cout&lt;&lt; countSputnik&lt;&lt;endl ;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(100);<br>
    getline(in,name);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost;<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    getline (in,name);<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    /*<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setprecision(12) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    */<br>
    ////////////////////////////////////////////////////////////////////<br>
    //getline(in, name);<br>
    //out &lt;&lt; endl &lt;&lt; name &lt;&lt; endl;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    out &lt;&lt; countSputnik &lt;&lt; endl;<br>
    getline(in,name);<br>
    allSputnik.resize(0);<br>
    index=-1; //��������� ��������<br>
    tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost;<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    getline (in,name);<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    G1<br>
    G28<br>
    R22<br>
    G19<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G9<br>
    R23<br>
    19472155.069 81015603.872 8 1314.191 51.000<br>
    18<br>
    G1<br>
    G28<br>
    R22<br>
    G19<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G8<br>
    R23<br>
    G1 G28 R22 G19 R12 G7 G3 G6 R6 R24 R5 G26 G11 G16 R13 R14 G9 R23 G8&nbsp;<br>
    23815383.399 23418101.711 20126478.966 20576502.049 20850572.801 20361179.631 22177242.661 23871188.467 23896969.354 22949017.462 23330231.749 23194678.499 21898256.651 24811902.872 19151353.321 21666798.485 20650945.821 19472152.449 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    23794425.041 23402498.509 20141642.176 20584598.589 20869652.326 20367330.686 22196301.185 23890335.007 23883323.395 22925234.933 23334086.485 23188096.286 21881612.664 24830710.969 19148858.027 21645612.101 0 19462739.332 20642124.208 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    int countSputnik;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(100);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = "";<br>
    /*<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    cout&lt;&lt; countSputnik&lt;&lt;endl ;<br>
    getline(in,name);<br>
    allSputnik.resize(0);// ������ ������ � ������� ����������<br>
    */<br>
    /*<br>
    int index=-1; //��������� ��������<br>
    string tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost;<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    getline (in,name);<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    */<br>
    /*<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    <br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setprecision(12) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    */<br>
    ////////////////////////////////////////////////////////////////////<br>
    //getline(in, name);<br>
    //out &lt;&lt; endl &lt;&lt; name &lt;&lt; endl;<br>
    for(int i=0; i&lt;4; i++) {<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    out &lt;&lt; countSputnik &lt;&lt; endl;<br>
    getline(in,name);<br>
    allSputnik.resize(0);<br>
    index=-1; //��������� ��������<br>
    tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    <br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost;<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    <br>
    getline (in,name);<br>
    getline (in,name);<br>
    <br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    <br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    18<br>
    G1<br>
    G28<br>
    R22<br>
    G19<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G9<br>
    R23<br>
    18<br>
    G1<br>
    G28<br>
    R22<br>
    G19<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G8<br>
    R23<br>
    18<br>
    G1<br>
    G28<br>
    R22<br>
    G19<br>
    R12<br>
    G7<br>
    G3<br>
    G6<br>
    R6<br>
    R24<br>
    R5<br>
    G26<br>
    G11<br>
    G16<br>
    R13<br>
    R14<br>
    G8<br>
    R23<br>
    1243988<br>
    19453454.30480937797.92821279.27712.000<br>
    19453454.30480937797.92821279.27712.000<br>
    G1 G28 R22 G19 R12 G7 G3 G6 R6 R24 R5 G26 G11 G16 R13 R14 G9 R23 G8 19453454.30480937797.92821279.27712.000&nbsp;<br>
    23815383.399 23418101.711 20126478.966 20576502.049 20850572.801 20361179.631 22177242.661 23871188.467 23896969.354 22949017.462 23330231.749 23194678.499 21898256.651 24811902.872 19151353.321 21666798.485 20650945.821 19472152.449 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    23794425.041 23402498.509 20141642.176 20584598.589 20869652.326 20367330.686 22196301.185 23890335.007 23883323.395 22925234.933 23334086.485 23188096.286 21881612.664 24830710.969 19148858.027 21645612.101 0 19462739.332 20642124.208 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    23773491.181 23386912.128 -2723.261 20592788.59 20888815.333 20373592.145 22215405.514 23909502.132 23869784.311 22901490.193 23338082.579 23181639.852 21865044.244 24849525.498 19146493.433 21624473.283 0 19453451.974 20633403.301 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 19453451.974 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    <strong>Task:</strong><br>
    Выведем данные Псевдодальности для каждого спутника.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat IRKL1119.txt<br>
    2.11 OBSERVATION DATA M (MIXED) RINEX VERSION / TYPE<br>
    ...<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER<br>
    11 11 19 0 0 0.0000000 0 18G 1G28R22G19R12G 7G 3G 6R 6R24R 5G26-0.000381360<br>
    &nbsp;&nbsp;&nbsp;&nbsp;G11G16R13R14G 8R23<br>
    23815384.399 23815383.399 125150709.498 3 3673.062 23.000<br>
    23815389.819 97520038.895 3 2862.131 23.000<br>
    ...<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;cmath&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    int countSputnik;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(100);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = "";<br>
    for(int i=0; i&lt;2880; i++) {<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    /*out &lt;&lt; countSputnik &lt;&lt; endl; */<br>
    getline(in,name);<br>
    allSputnik.resize(0);<br>
    index=-1; //��������� ��������<br>
    tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    /*<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost=0;<br>
    /*<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    */<br>
    string b = "";<br>
    getline (in, b);<br>
    a ="";<br>
    if(b.size()&gt;=30){<br>
    a=b.substr(17,13);<br>
    }<br>
    int tochka=-1;<br>
    int chislo=0;<br>
    for (int i=0; i&lt;a.size(); i++){<br>
    &nbsp;&nbsp;if (a[i]&gt;='0' &amp;&amp; a[i]&lt;='9'){<br>
    &nbsp;&nbsp; dalnost = dalnost *10 + (a[i]-'0');<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;else {<br>
    &nbsp;&nbsp; if(a[i]== '.') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tochka=i;<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(tochka != -1){<br>
    &nbsp;&nbsp;chislo = a.size()-1 - tochka;<br>
    &nbsp;&nbsp;chislo = (int) pow(10, (double)chislo);<br>
    &nbsp;&nbsp;dalnost=dalnost/chislo;<br>
    }<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    G1 G28 R22 G19 R12 G7 G3 G6 R6 R24 R5 G26 G11 G16 R13 R14 G8 R23 G15 G22 G17 R7 R15 R17 R8 G32 G20 G9 R1 R16 G4 R18 R2 G12 G2 R9 G10 G23 G25 R19 R10 G13 G5 R4 G31 R11 G29 R20 G30 G21 R21 G18 G14&nbsp;<br>
    23815383.399 23418101.711 20126478.966 20576502.049 20850572.801 20361179.631 22177242.661 23871188.467 23896969.354 22949017.462 23330231.749 23194678.499 21898256.651 24811902.872 19151353.321 21666798.485 20650945.821 19472152.449 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    23794425.041 23402498.509 20141642.176 20584598.589 20869652.326 20367330.686 22196301.185 23890335.007 23883323.395 22925234.933 23334086.485 23188096.286 21881612.664 24830710.969 19148858.027 21645612.101 20642124.208 19462739.332 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0&nbsp;<br>
    ...<br>
    <strong>Task:</strong><br>
    Выведем данные из файла Sirftin.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat sirfrin1.txt<br>
    2.10 OBSERVATION DATA G (GPS) RINEX VERSION / TYPE<br>
    ...<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER<br>
    15 5 18 0 41 23.0000613 0 11G 1G12G32G24G22G14G11G 4G18G31G17<br>
    23527987.056 8<br>
    21972648.359 8<br>
    22403365.951 6<br>
    23784621.452 7<br>
    21148286.543 6<br>
    20408196.378 4<br>
    24488332.428 4<br>
    23108442.059 5<br>
    23196661.017 4<br>
    22514486.129 5<br>
    25648439.341 3<br>
    15 5 18 0 41 24.0000613 0 11G 1G12G32G24G22G14G11G 4G18G31G17<br>
    23527900.192 8<br>
    21972620.569 8<br>
    22402887.237 5<br>
    23785272.449 7<br>
    21148685.515 6<br>
    20408150.444 4<br>
    24488620.925 4<br>
    23108699.683 5<br>
    23197296.183 4<br>
    22513871.405 5<br>
    25648503.069 3<br>
    ...<br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;cmath&gt;<br>
    #include &lt;vcl.h&gt;&gt;<br>
    #pragma hdrstop<br>
    <br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("sirfrin1.txt");<br>
    ofstream out ("output.txt");<br>
    //////// ������� END OF HEADER<br>
    string a;<br>
    while(true) {<br>
    &nbsp;&nbsp;getline (in,a);<br>
    &nbsp;&nbsp;if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    //////// ����<br>
    string name; // ������� ������<br>
    int temp; // �����<br>
    double temp2; // ����� � ������<br>
    int countSputnik; // ���������� ���������<br>
    vector &lt;vector &lt;double&gt; &gt; info; // ������� ������<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(15); // ������ �������<br>
    vector &lt;string&gt; Sputnik; // ������� ������� �� ���������<br>
    vector &lt;string&gt; allSputnik; // ������� ������� �� ����� ����������<br>
    int index=-1; // ��������� ��������<br>
    string tempName = ""; // ������ �������� ���������<br>
    //////// ������� ������� � ���������<br>
    for(int i=0; i&lt;4797; i++) { // ������� ����� ����<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp2;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; countSputnik;<br>
    &nbsp;&nbsp;// out &lt;&lt; countSputnik &lt;&lt; endl; // ���������� ���������<br>
    //////////////// ��������� �� �����<br>
    &nbsp;&nbsp;getline(in,name);<br>
    &nbsp;&nbsp;// out &lt;&lt; name; // �������� ���������<br>
    //////////////// ��������� �������� ���������<br>
    &nbsp;&nbsp;allSputnik.resize(0);<br>
    &nbsp;&nbsp;index=-1;<br>
    &nbsp;&nbsp;tempName = "";<br>
    &nbsp;&nbsp;for(int i=0; i&lt; name.size(); i++) {<br>
    &nbsp;&nbsp; if(name[i] == '-') // ���� ��������� -<br>
    &nbsp;&nbsp; break; // �� ���������<br>
    &nbsp;&nbsp; if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') { // ���� ��������� �����<br>
    &nbsp;&nbsp;&nbsp;&nbsp;index++; // �� ��������� ������<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if (name[i] != ' '){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tempName = tempName + name[i];<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;//tempName="";<br>
    //////////////// ������� ��� ��������� ��������� ������ ������<br>
    &nbsp;&nbsp;/* for(int i=0; i&lt;allSputnik.size(); i++){<br>
    &nbsp;&nbsp; out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    &nbsp;&nbsp;} */<br>
    //////////////// 2�� ������ �������� ���������<br>
    &nbsp;&nbsp;/*if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    &nbsp;&nbsp; //getline(in,name); // ��������� ������ �� �����<br>
    &nbsp;&nbsp; for(int i=0; i&lt;name.size(); i++){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; index++;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tempName="";<br>
    &nbsp;&nbsp;&nbsp;&nbsp; }<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if (name[i] != ' '){<br>
    &nbsp;&nbsp;&nbsp;&nbsp; tempName = tempName + name[i];<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;/* for(int i=0; i&lt;allSputnik.size(); i++){<br>
    &nbsp;&nbsp; out &lt;&lt; allSputnik[i] &lt;&lt; endl; // ������� ��� ��������� ��������� � ������ � ������ ������<br>
    &nbsp;&nbsp;} */<br>
    /////////////// ��������� ���������� ���������<br>
    &nbsp;&nbsp;info.push_back(tempVector);<br>
    &nbsp;&nbsp;for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    &nbsp;&nbsp; double dalnost=0;<br>
    &nbsp;&nbsp; string b = "";<br>
    &nbsp;&nbsp; getline (in, b);<br>
    &nbsp;&nbsp; a ="";<br>
    &nbsp;&nbsp; if(b.size()&gt;=14){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;a=b.substr(2,12); // �������� ������ ��� ����������<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; // out &lt;&lt; a &lt;&lt; endl; // ������� ���������� ���������<br>
    /////////////////////// ����������� ������ ������� � ������� ��� ���� ����� ���������� ������ ������<br>
    &nbsp;&nbsp; int tochka=-1;<br>
    &nbsp;&nbsp; int chislo=0;<br>
    &nbsp;&nbsp; for (int i=0; i&lt;a.size(); i++){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if (a[i]&gt;='0' &amp;&amp; a[i]&lt;='9'){<br>
    &nbsp;&nbsp;&nbsp;&nbsp; dalnost = dalnost *10 + (a[i]-'0');<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;&nbsp;else {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; if(a[i]== '.') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tochka=i;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; }<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if(tochka != -1){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;chislo = a.size()-1 - tochka;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;chislo = (int) pow(10, (double)chislo);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;dalnost=dalnost/chislo;<br>
    &nbsp;&nbsp; }<br>
    /////////////////////// ��������� �������� � ��������� � ������������<br>
    &nbsp;&nbsp; // getline (in,name); //��������� �� ����� ����� ������<br>
    &nbsp;&nbsp; index=-1;<br>
    &nbsp;&nbsp; for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if(index == -1) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; else {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    &nbsp;&nbsp; }<br>
    <br>
    &nbsp;&nbsp;}<br>
    }<br>
    //////// ������� ���������� �� �������<br>
    // out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    /////// ������� ���������� �� �������<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    &nbsp;&nbsp;for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp; out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;out &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    root@kvmubuntu:~# cat output.txt<br>
    G1 G12 G32 G24 G22 G14 G11 G4 G18 G31 G17 G3 G25 G26 G29&nbsp;<br>
    23527987.056 21972648.359 22403365.951 23784621.452 21148286.543 20408196.378 24488332.428 23108442.059 23196661.017 22514486.129 25648439.341 0 0 0 0&nbsp;<br>
    23527900.192 21972620.569 22402887.237 23785272.449 21148685.515 20408150.444 24488620.925 23108699.683 23197296.183 22513871.405 25648503.069 0 0 0 0&nbsp;<br>
    23527815.469 21972594.92 22402410.598 23785925.499 21149086.34 20408107.268 24488915.359 23108959.419 23197938.791 22513258.71 25648554.131 0 0 0 0&nbsp;<br>
    23527729.677 21972568.22 22401932.854 23786577.382 21149485.828 20408062.76 24489187.365 23109217.855 23198578.688 22512592.942 25648601.174 0 0 0 0&nbsp;<br>
    ...<br>
    <strong>Task:</strong><br>
    Нарисуйте График с файла Sirfrin1.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;cmath&gt;<br>
    #include &lt;vcl.h&gt;&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("sirfrin1.txt");<br>
    ofstream out ("output.txt");<br>
    //////// ������� END OF HEADER<br>
    string a;<br>
    while(true) {<br>
    &nbsp;&nbsp;getline (in,a);<br>
    &nbsp;&nbsp;if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    //////// ����<br>
    string name; // ������� ������<br>
    int temp; // �����<br>
    double temp2; // ����� � ������<br>
    int countSputnik; // ���������� ���������<br>
    vector &lt;vector &lt;double&gt; &gt; info; // ������� ������<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(15); // ������ �������<br>
    vector &lt;string&gt; Sputnik; // ������� ������� �� ���������<br>
    vector &lt;string&gt; allSputnik; // ������� ������� �� ����� ����������<br>
    int index=-1; // ��������� ��������<br>
    string tempName = ""; // ������ �������� ���������<br>
    //////// ������� ������� � ���������<br>
    for(int i=0; i&lt;4797; i++) { // ������� ����� ����<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; temp2;<br>
    &nbsp;&nbsp;in &gt;&gt; temp;<br>
    &nbsp;&nbsp;in &gt;&gt; countSputnik;<br>
    &nbsp;&nbsp;// out &lt;&lt; countSputnik &lt;&lt; endl; // ���������� ���������<br>
    //////////////// ��������� �� �����<br>
    &nbsp;&nbsp;getline(in,name);<br>
    &nbsp;&nbsp;// out &lt;&lt; name; // �������� ���������<br>
    //////////////// ��������� �������� ���������<br>
    &nbsp;&nbsp;allSputnik.resize(0);<br>
    &nbsp;&nbsp;index=-1;<br>
    &nbsp;&nbsp;tempName = "";<br>
    &nbsp;&nbsp;for(int i=0; i&lt; name.size(); i++) {<br>
    &nbsp;&nbsp; if(name[i] == '-') // ���� ��������� -<br>
    &nbsp;&nbsp; break; // �� ���������<br>
    &nbsp;&nbsp; if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') { // ���� ��������� �����<br>
    &nbsp;&nbsp;&nbsp;&nbsp;index++; // �� ��������� ������<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if (name[i] != ' '){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tempName = tempName + name[i];<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;//tempName="";<br>
    //////////////// ������� ��� ��������� ��������� ������ ������<br>
    &nbsp;&nbsp;/* for(int i=0; i&lt;allSputnik.size(); i++){<br>
    &nbsp;&nbsp; out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    &nbsp;&nbsp;} */<br>
    //////////////// 2�� ������ �������� ���������<br>
    &nbsp;&nbsp;/*if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    &nbsp;&nbsp; //getline(in,name); // ��������� ������ �� �����<br>
    &nbsp;&nbsp; for(int i=0; i&lt;name.size(); i++){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; index++;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; if(tempName != "") {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tempName="";<br>
    &nbsp;&nbsp;&nbsp;&nbsp; }<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if (name[i] != ' '){<br>
    &nbsp;&nbsp;&nbsp;&nbsp; tempName = tempName + name[i];<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;/* for(int i=0; i&lt;allSputnik.size(); i++){<br>
    &nbsp;&nbsp; out &lt;&lt; allSputnik[i] &lt;&lt; endl; // ������� ��� ��������� ��������� � ������ � ������ ������<br>
    &nbsp;&nbsp;} */<br>
    /////////////// ��������� ���������� ���������<br>
    &nbsp;&nbsp;info.push_back(tempVector);<br>
    &nbsp;&nbsp;for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    &nbsp;&nbsp; double dalnost=0;<br>
    &nbsp;&nbsp; string b = "";<br>
    &nbsp;&nbsp; getline (in, b);<br>
    &nbsp;&nbsp; a ="";<br>
    &nbsp;&nbsp; if(b.size()&gt;=14){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;a=b.substr(2,12); // �������� ������ ��� ����������<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; // out &lt;&lt; a &lt;&lt; endl; // ������� ���������� ���������<br>
    /////////////////////// ����������� ������ ������� � ������� ��� ���� ����� ���������� ������ ������<br>
    &nbsp;&nbsp; int tochka=-1;<br>
    &nbsp;&nbsp; int chislo=0;<br>
    &nbsp;&nbsp; for (int i=0; i&lt;a.size(); i++){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if (a[i]&gt;='0' &amp;&amp; a[i]&lt;='9'){<br>
    &nbsp;&nbsp;&nbsp;&nbsp; dalnost = dalnost *10 + (a[i]-'0');<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp;&nbsp;&nbsp;else {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; if(a[i]== '.') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tochka=i;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; }<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if(tochka != -1){<br>
    &nbsp;&nbsp;&nbsp;&nbsp;chislo = a.size()-1 - tochka;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;chislo = (int) pow(10, (double)chislo);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;dalnost=dalnost/chislo;<br>
    &nbsp;&nbsp; }<br>
    /////////////////////// ��������� �������� � ��������� � ������������<br>
    &nbsp;&nbsp; // getline (in,name); //��������� �� ����� ����� ������<br>
    &nbsp;&nbsp; index=-1;<br>
    &nbsp;&nbsp; for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp;&nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;&nbsp;&nbsp;}<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; if(index == -1) {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;&nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp; else {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    &nbsp;&nbsp; }<br>
    <br>
    &nbsp;&nbsp;}<br>
    }<br>
    //////// ������� ���������� �� �������<br>
    // out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    /////// ������� ���������� �� �������<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    &nbsp;&nbsp;for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp; out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;out &lt;&lt; endl;<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++){<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][0] &lt;&lt; setw(14) &lt;&lt; info[i][1] &lt;&lt; endl;<br>
    Form1-&gt;Memo1-&gt;Lines-&gt;Add(info[i][0]);<br>
    Form1-&gt;Memo2-&gt;Lines-&gt;Add(info[i][1]);<br>
    Form1-&gt;Memo3-&gt;Lines-&gt;Add(info[i][0]-info[i][1]);<br>
    //Series1-&gt;Add(info[i][0],clBlue);<br>
    //Series2-&gt;Add(info[i][1],clBlue);<br>
    Series2-&gt;Add(info[i][0]-info[i][1],clBlue);<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    <strong>Task:</strong><br>
    Нарисуйте График И Вычислите Разницу.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    root@kvmubuntu:~# cat Unit1.cpp<br>
    //---------------------------------------------------------------------------<br>
    #include &lt;iostream&gt;<br>
    #include &lt;vector&gt;<br>
    #include &lt;fstream&gt;<br>
    #include &lt;string.h&gt;<br>
    #include &lt;iomanip.h&gt;<br>
    #include &lt;cmath&gt;<br>
    #include &lt;vcl.h&gt;<br>
    #pragma hdrstop<br>
    #include "Unit1.h"<br>
    //---------------------------------------------------------------------------<br>
    #pragma package(smart_init)<br>
    #pragma resource "*.dfm"<br>
    TForm1 *Form1;<br>
    //---------------------------------------------------------------------------<br>
    __fastcall TForm1::TForm1(TComponent* Owner)<br>
    : TForm(Owner)<br>
    {<br>
    ifstream in ("IRKL1119.txt");<br>
    ofstream out ("output.txt");<br>
    string a;<br>
    //���������� �� �� END OF HEADER<br>
    while(true) {<br>
    getline (in,a);<br>
    if(a == "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; END OF HEADER") {<br>
    break;<br>
    }<br>
    }<br>
    string name;<br>
    // ������� ������� � ���������<br>
    int temp;<br>
    double temp2;<br>
    int countSputnik;<br>
    vector &lt;vector &lt;double&gt; &gt; info;<br>
    vector &lt;double&gt; tempVector;<br>
    tempVector.resize(53);<br>
    vector &lt;string&gt; Sputnik;<br>
    vector &lt;string&gt; allSputnik;// ������ ������ � ������� ����������<br>
    int index=-1; //��������� ��������<br>
    string tempName = "";<br>
    for(int i=0; i&lt;2880; i++) {<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; temp2;<br>
    in &gt;&gt; temp;<br>
    in &gt;&gt; countSputnik;<br>
    /*out &lt;&lt; countSputnik &lt;&lt; endl; */<br>
    getline(in,name);<br>
    allSputnik.resize(0);<br>
    index=-1; //��������� ��������<br>
    tempName = ""; //<br>
    for(int i=0; i&lt; name.size(); i++) {<br>
    if(name[i] == '-')<br>
    break;<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    index++;<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    }<br>
    if (name[i] != ' '){<br>
    tempName = tempName + name[i];<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    tempName="";<br>
    if(index &lt;= countSputnik-1) { //��������� ��������� �� ����� ���� ��������<br>
    //2 stroka<br>
    getline(in,name);<br>
    for(int i=0; i&lt;name.size(); i++){<br>
    if(name[i] &gt;= 'A' &amp;&amp; name[i] &lt;= 'Z') {<br>
    &nbsp;&nbsp;index++;<br>
    &nbsp;&nbsp;if(tempName != "") {<br>
    &nbsp;&nbsp; allSputnik.push_back(tempName);<br>
    &nbsp;&nbsp; tempName="";<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if (name[i] != ' '){<br>
    &nbsp;&nbsp;tempName = tempName + name[i];<br>
    }<br>
    }<br>
    }<br>
    if(tempName != "") {<br>
    allSputnik.push_back(tempName);<br>
    tempName="";<br>
    }<br>
    /*<br>
    for(int i=0; i&lt;allSputnik.size(); i++){<br>
    out &lt;&lt; allSputnik[i] &lt;&lt; endl;<br>
    }<br>
    */<br>
    info.push_back(tempVector);<br>
    for(int i = 0; i&lt;allSputnik.size(); i++) {<br>
    double dalnost=0;<br>
    /*<br>
    in &gt;&gt; dalnost;<br>
    in &gt;&gt; dalnost;<br>
    */<br>
    string b = "";<br>
    getline (in, b);<br>
    a ="";<br>
    if(b.size()&gt;=14){<br>
    a=b.substr(1,13);<br>
    }<br>
    int tochka=-1;<br>
    int chislo=0;<br>
    for (int i=0; i&lt;a.size(); i++){<br>
    &nbsp;&nbsp;if (a[i]&gt;='0' &amp;&amp; a[i]&lt;='9'){<br>
    &nbsp;&nbsp; dalnost = dalnost *10 + (a[i]-'0');<br>
    &nbsp;&nbsp;}<br>
    &nbsp;&nbsp;else {<br>
    &nbsp;&nbsp; if(a[i]== '.') {<br>
    &nbsp;&nbsp;&nbsp;&nbsp;tochka=i;<br>
    &nbsp;&nbsp; }<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(tochka != -1){<br>
    &nbsp;&nbsp;chislo = a.size()-1 - tochka;<br>
    &nbsp;&nbsp;chislo = (int) pow(10, (double)chislo);<br>
    &nbsp;&nbsp;dalnost=dalnost/chislo;<br>
    }<br>
    getline (in,name);<br>
    index=-1;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    &nbsp;&nbsp;if(allSputnik[i] == Sputnik[j]) {<br>
    &nbsp;&nbsp; index = j;<br>
    &nbsp;&nbsp; break;<br>
    &nbsp;&nbsp;}<br>
    }<br>
    if(index == -1) {<br>
    &nbsp;&nbsp;Sputnik.push_back(allSputnik[i]);<br>
    &nbsp;&nbsp;info[info.size()-1][Sputnik.size()-1] = dalnost;<br>
    }<br>
    else {<br>
    &nbsp;&nbsp;info[info.size()-1][index] = dalnost;<br>
    }<br>
    }<br>
    }<br>
    // out &lt;&lt; endl;<br>
    for(int j=0; j&lt;Sputnik.size(); j++) {<br>
    out &lt;&lt; setw(13) &lt;&lt; Sputnik[j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++) {<br>
    for(int j=0; j&lt;info[i].size(); j++) {<br>
    &nbsp;&nbsp;out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][j] &lt;&lt; " ";<br>
    }<br>
    out &lt;&lt; endl;<br>
    }<br>
    out &lt;&lt; endl;<br>
    for(int i=0; i&lt;info.size(); i++){<br>
    Form1-&gt;Memo1-&gt;Lines-&gt;Add(info[i][0]);<br>
    Form1-&gt;Memo2-&gt;Lines-&gt;Add(info[i][1]);<br>
    //Form1-&gt;Memo3-&gt;Lines-&gt;Add(info[i][0]-info[i][1]);<br>
    Series1-&gt;Add(info[i][0],clBlue);<br>
    Series2-&gt;Add(info[i][1],clBlue);<br>
    //out &lt;&lt; setw(13) &lt;&lt; setprecision(13) &lt;&lt; info[i][0] &lt;&lt; setw(14) &lt;&lt; info[i][1] &lt;&lt; endl;<br>
    }<br>
    }<br>
    //---------------------------------------------------------------------------<br>
    <strong>Task:</strong><br>
    Попробуем просто сделать это все на графическом интерфейсе, вывести данные двух спутников, плюс еще нарисовать графики этих данных для двух спутников.<br>
    Теперь нужно обработать и сортировать данные с геометрической дальностью для спутников. Файл называется igr18451.txt. Вот как выглядят данные, которые нужно отсортировать. Тут уже одна эпоха равняется 15 минутам.<br>
    То что я выделил, это координаты спутника X,Y,Z. Именно их и нужно отсортировать. PG01 - название первого спутника. Попробуем вывести данные именно для него.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    PG04 16571.755106 7091.147720 19268.134634<br>
    PG04 17081.817393 9222.831883 17918.904800<br>
    PG04 17633.922784 11162.951350 16256.328779<br>
    PG04 18194.986791 12883.319207 14310.615388<br>
    PG04 18728.745598 14363.489413 12116.696076<br>
    PG04 19197.262350 15591.290270 9713.525830<br>
    PG04 19562.489921 16563.032391 7143.333216<br>
    PG04 19787.827341 17283.391677 4450.837454<br>
    PG04 19839.609715 17764.980464 1682.449322<br>
    PG04 19688.476298 18027.631365 -1114.528992<br>
    PG04 19310.568086 18097.427949 -3892.691773<br>
    PG04 18688.514262 18005.524210 -6605.294077<br>
    PG04 17812.175758 17786.800613 -9206.983073<br>
    PG04 16679.123638 17478.408399 -11654.488894<br>
    PG04 15294.839581 17118.255856 -13907.269035<br>
    PG04 13672.635233 16743.490595 -15928.101701<br>
    PG04 11833.296299 16389.030589 -17683.624513<br>
    PG04 9804.465824 16086.194088 -19144.815686<br>
    PG04 7619.789018 15861.474593 -20287.415200<br>
    ...<br>
    <strong>Task:</strong><br>
    Это мы вывели координаты X,Y,Z и название спутника. Но мне теперь нужно вывести данные только Х для первого спутника.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    14736.411108<br>
    15414.203154<br>
    16201.304785<br>
    17074.555745<br>
    18004.439905<br>
    18956.228081<br>
    19891.328698<br>
    20768.792721<br>
    21546.914135<br>
    ...<br>
    <strong>Task:</strong><br>
    Аналогично выводятся только для Y и Z выводим данные. Просто нужно поменять в коде x на y или z.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Task:</strong><br>
    Аналогично нужно вывести данные псевдодальности полученные с моего приемника. файл - sirfrin1.txt.<br>
    Тут мы увидим только две данные для спутников. Первые, это дальность, которую как раз и нужно отсортировать по каждом НС, а вторые - сигналы спутника, которые нас не особо не интересуют. А также эпоха здесь начинается не с нуля, как мы видим, а с 41 минуты 23 секунды. Это тоже нужно учитывать, когда нужно будет сравнивать эти данные с ГД.<br>
    # Разработка программы Обработка и сортировка данных в файлах Rinex формата.<br>
    <strong>Decision:</strong><br>
    Мы задачу выполнили (отсортировать данные ГД и ПД по каждом навигационному спутнику), остается только обработать эти данные по формулам и посторить по ним графики через Эксель.<br>
    <strong>Task:</strong><br>
    Экспериментальные результаты.<br>
    # Спутниковые радионаввигационные системы.<br>
    <strong>Decision:</strong><br>
    Для наглядности на рис. 14 показан пример измерения навигационных сигналов, принимаемых с НС GPS1 и GPS20, взятый из статьи [6]. По горизонтали отложены номера 30-ти секундных интервалов (эпох) от 0 часов всемирного времени. В верхней части рисунка даны результаты вычислений углов места НС GPS1 (пунктир) и GPS20 (точки). В нижней части рисунка тонкой линией в соответствии с формулой (3.4) показана разность измеренных псевдодальностей за вычетом разности ГД от этих НС с коррекцией запаздывания лучей в тропосфере по формуле (4.5). Для расчета ГД использовались уточненные эфемериды SP3 [6].&nbsp;<br>
    Рис. 14. Пример измерений вариаций ионосферы:
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:589/395;" src="/media/drawing14.png" width="589" height="395">
</figure>
<p>
    Здесь же для сравнения жирной линией приведена разность ионосферных ошибок для этих же НС по данным двухчастотного приемника JPS EGGDT станции Иркутск (IRKL).&nbsp;<br>
    На рис. 15 показана средняя часть рис. 14 для детального сравнения данных о вариациях ионосферной ошибки, определяемой вариациями ПЭС между двумя НС [6].<br>
    Рис.15. Сравнение данных одночастотного и двухчастотного приемников:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:509/275;" src="/media/drawing15.png" width="509" height="275">
</figure>
<p>
    Видно, что для высоких углов места в среднем наблюдается хорошее совпадение результатов, полученных разными методами. Следует отметить, что случайные отклонения у одночастотного приемника примерно в два раза больше. При приближении НС к горизонту данные одночастотного приемника начинают сильно отличаться от двухчастотного, и при углах места около 5° различие доходит до 15-20 м (~ 60 нс). Вероятно, это связано с влиянием тропосферы и неучтенной при коррекции «влажной» составляющей тропосферной погрешности [6].<br>
    Приведенные данные свидетельствуют о близости результатов определения разности ионосферных ошибок двухчастотным и одночастотным приемниками. Как видно из сравнения описанных результатов, в диапазоне углов места больше 15° две кривые хорошо совпадают, различие между ними в 90% случаев не превышает 2 м (7 нс), при регулярном ходе около 20 м (70 нс) [6].<br>
    Для сравнения, я пытался построить свои примеры измерения навигационных сигналов. В прил. 3 показан код программы на языке С++, которая обрабатывает и сортирует данные ПД по каждому НС. На табл. 4 показан пример вычислений и интерпретаций данных с помощью EXCEL:<br>
    Таблица 4. Вычисления данных с помощью Excel:&nbsp;
</p>
<figure class="image image-style-align-center">
    <img style="aspect-ratio:623/495;" src="/media/table4.png" width="623" height="495">
</figure>
<p>
    где x, y, z – координаты приёмника, а Xi, Yi, Zi – координаты спутника, ГД- вычисленная по формуле (4.1) геометрическая дальность, ПД – пседодальность и последний столбец является разностью ошибок ионосферы для двух спутников G1и G28 вычисленная по формуле (4.4).<br>
    На рис. 16-19 построены разности ошибок ионосферы для двух НС в один момент времени. Первая часть данных взяты из собственных измерений, а вторая часть данных для сравнения давались мне руководителем. По горизонтали отложены номера 15-ти минутных интервалов.&nbsp;<br>
    Рис. 16. Пример измерений, принимаемых с GPS 1 и GPS 28, Рис. 17. Пример измерений, принимаемых с GPS 20 и GPS 32, Рис. 18. Пример измерений, принимаемых с GPS 2 и GPS 5, Рис. 19. Пример измерений, принимаемых с GPS 1 и GPS 4:&nbsp;
</p>
<figure class="image">
    <img style="aspect-ratio:581/399;" src="/media/drawing16.png" width="581" height="399">
</figure>
<figure class="image">
    <img style="aspect-ratio:509/313;" src="/media/drawing17.png" width="509" height="313">
</figure>
<figure class="image">
    <img style="aspect-ratio:606/330;" src="/media/drawing18.png" width="606" height="330">
</figure>
<figure class="image">
    <img style="aspect-ratio:589/409;" src="/media/drawing19.png" width="589" height="409">
</figure>
<p>
    Разность псевдодальности и геометрической дальности на рис. 16-17 является разностью ионосферной задержки и может быть использована для коррекции ионосферы. На рис. 18-19 получились большие разности, и такие данные использовать для уточнения состояния ионосферы при её оперативной коррекции нельзя.<br>
    <strong>Decision:</strong><br>
    Для защиты диссертации по теме "Использование данных с одночастотных приемников спутниковых радионавигационных систем для коррекции модели ионосферы" освоил технологию приёма получения данных с одночастотных приемников спутниковых радионавигационных систем, получил данные, разработал программу на C++, которая обрабатывает и сортирует данные двух координат из файла по столбцам, рисует график, чтобы увидеть желаемый результат в точности определения координат спутников, рассмотрел способы уменьшения ошибок измерения псевдодальности и показал, что из-за нестабильности аппаратуры потребителя информация о состоянии ионосферы может быть получена в каждый момент времени по разностям ПД двух навигационных спутников&nbsp;<br>
    <strong>Decision:</strong><br>
    Защитил диплом выпускной квалификационной работы бакалавра и магистерскую диссертацию.<br>
    <strong>Source:</strong><br>
    # <a href="https://forum.calculate-linux.org/t/windows-qemu-kvm-libvirt/9357">https://forum.calculate-linux.org/t/windows-qemu-kvm-libvirt/9357</a><br>
    # <a href="https://blog.sedicomm.com/2019/07/21/rdesktop-klient-rdp-dlya-podklyucheniya-rabochego-stola-windows-iz-linux/">https://blog.sedicomm.com/2019/07/21/rdesktop-klient-rdp-dlya-podklyucheniya-rabochego-stola-windows-iz-linux/</a><br>
    # <a href="https://learn.microsoft.com/ru-ru/windows-server/administration/openssh/openssh_install_firstuse">https://learn.microsoft.com/ru-ru/windows-server/administration/openssh/openssh_install_firstuse</a><br>
    # <a href="https://learn.microsoft.com/ru-ru/powershell/scripting/learn/remoting/ssh-remoting-in-powershell-core?view=powershell-7.3">https://learn.microsoft.com/ru-ru/powershell/scripting/learn/remoting/ssh-remoting-in-powershell-core?view=powershell-7.3</a><br>
    # <a href="https://learn.microsoft.com/en-us/powershell/module/storage/dismount-diskimage?view=windowsserver2022-ps">https://learn.microsoft.com/en-us/powershell/module/storage/dismount-diskimage?view=windowsserver2022-ps</a><br>
    # <a href="https://superuser.com/questions/499264/how-can-i-mount-an-iso-via-powershell-programmatically">https://superuser.com/questions/499264/how-can-i-mount-an-iso-via-powershell-programmatically</a><br>
    # <a href="https://winitpro.ru/index.php/2016/03/31/sftp-ssh-ftp-na-windows-server-2012-r2/">https://winitpro.ru/index.php/2016/03/31/sftp-ssh-ftp-na-windows-server-2012-r2/</a><br>
    # <a href="https://mhelp.pro/ru/kak-zapustit-powershell-ot-imeni-administratora/?ysclid=lmzwqntxfi559273426">https://mhelp.pro/ru/kak-zapustit-powershell-ot-imeni-administratora/?ysclid=lmzwqntxfi559273426</a><br>
    # <a href="https://remontka.pro/text-files-cmd-powershell/?ysclid=lmzy2p5172409325479">https://remontka.pro/text-files-cmd-powershell/?ysclid=lmzy2p5172409325479</a><br>
    # <a href="https://www.digitalocean.com/community/tutorials/sftp-ru">https://www.digitalocean.com/community/tutorials/sftp-ru</a><br>
    # <a href="http://ftp.glonass-iac.ru/guide/navfaq.php">http://ftp.glonass-iac.ru/guide/navfaq.php</a><br>
    # <a href="https://ru.wtuseripedia.org/wtuseri/%D0%A1%D0%BF%D1%83%D1%82%D0%BD%D0%B8%D0%BA%D0%BE%D0%B2%D0%B0%D1%8F_%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%B0_%D0%BD%D0%B0%D0%B2%D0%B8%D0%B3%D0%B0%D1%86%D0%B8%D0%B8">https://ru.wtuseripedia.org/wtuseri/%D0%A1%D0%BF%D1%83%D1%82%D0%BD%D0%B8%D0%BA%D0%BE%D0%B2%D0%B0%D1%8F_%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%B0_%D0%BD%D0%B0%D0%B2%D0%B8%D0%B3%D0%B0%D1%86%D0%B8%D0%B8</a><br>
    # Харисов В.Н. Глобальная спутниковая радионавигационная система ГЛОНАСС<br>
    # Грудинская Г.П. Распространение радиоволн<br>
    # <a href="http://begin.clan.su/news/speciftusera_provedenija_psevdodalnomernykh_i_fazov/2013-09-18-135">http://begin.clan.su/news/speciftusera_provedenija_psevdodalnomernykh_i_fazov/2013-09-18-135</a><br>
    # <a href="http://rrv.iszf.irk.ru/sites/default/files/conf2014/articles/tom2/17-20.pdf">http://rrv.iszf.irk.ru/sites/default/files/conf2014/articles/tom2/17-20.pdf</a><br>
    # <a href="http://www.u-blox.com">http://www.u-blox.com</a><br>
    # Дэвис К. Радиоволны в ионосфере<br>
    # <a href="https://www.youtube.com/watch?v=bDvVosvyVp0&amp;list=LL&amp;index=315">https://www.youtube.com/watch?v=bDvVosvyVp0&amp;list=LL&amp;index=315</a>
</p>