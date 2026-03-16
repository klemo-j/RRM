<h1 align="center">Zadanie 1.4 - ROS Service Server</h1>

<p>
  <strong>Cieľom zadania 1.4</strong> je navrhnúť mechanizmus na ukladanie polôh robota, ktoré budú tvoriť jeho trajektóriu. V priemyselnej praxi sa s týmto často stretnete pod pojmom "teach point" alebo "trajectory". 
</p>
<p>
  Cieľom je naučiť robot vykonávať túto trajektóriu automaticky počas výrobného cyklu. Vašou úlohou bude vytvoriť vlastný <strong>Service Server</strong>, ktorý bude schopný uložiť aktuálnu polohu robota. Správa z request service bude obsahovať maximálnu rýchlosť, akou sa robot môže pohybovať k naučenému bodu. Tieto naučené body následne uložte do súboru pre ďalšie využitie.
</p>

<hr>

<h2>✅ Úlohy a hodnotenie (Max. 2 body)</h2>
<ol>
  <li>
    <strong>[1 b] Metóda na ukladanie polohy:</strong> Vytvorte metódu na uloženie polohy do súboru, z pohľadu OOP by nemala byť súčasťou triedy <em>Teleop</em>. V súbore bude uložené ID bodu, všetky tri natočenia kĺbov a maximálna rýchlosť definovaná užívateľom.
  </li>
  <li>
    <strong>[1 b] Service Server na ukladanie:</strong> Vytvorte <em>Service Server</em> s vlastnou správou. Obslužná funkcia prečíta aktuálny stav robota a pomocou metódy z bodu jedna ho uloží do súboru.
  </li>
</ol>

<hr>

<h2>🌟 BONUS</h2>
<ul>
  <li>
    <strong>[2 b] Service Server na prehrávanie trajektórie:</strong> Vytvorte <em>Service Server</em>, ktorý prečíta súbor a postupne odošle uložené body na robot ako príkaz na pohyb.
  </li>
</ul>

<hr>

<h2>💡 Tipy</h2>
<ul>
  <li>Odporúčame pokračovať na balíku z predošlého zadania.</li>
  <li>Na prácu so súborom môžete použiť štandardnú knižnicu <code>&lt;fstream&gt;</code> alebo využiť poznatky z predošlých predmetov.</li>
</ul>
