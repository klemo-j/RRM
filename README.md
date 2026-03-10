# Projekt RRM (Riadenie robotických mechanizmov)

Tento repozitár slúži na odovzdávanie a verzionovanie zadaní z predmetu RRM. Kód je písaný v systéme **ROS 2**.

## 🤖 Čo je ROS 2?
**ROS (Robot Operating System)** nie je operačný systém v pravom zmysle slova, ale tzv. *middleware* – sada softvérových nástrojov a knižníc, ktoré pomáhajú pri budovaní aplikácií pre roboty. Funguje na princípe uzlov (**nodes**), ktoré medzi sebou komunikujú posielaním správ cez témy (**topics**).

---

## 🛠️ Základné príkazy (Cheat Sheet)

Pred spustením akéhokoľvek príkazu sa uisti, že si v koreňovom priečinku svojho workspace-u (napr. `~/ros2_ws`).

### 1. Build (Zostavenie projektu)
Na skompilovanie tvojich balíčkov použi nástroj `colcon`:
```bash
colcon build
