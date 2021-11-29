# Moteur 3D Ray-tracing

## Description

Un projet universitaire (2021).

Le code est situé dans la branche master.

## Scene finale du projet

<p align=center>
  <a href="https://drive.google.com/uc?export=view&id=1BgD3N7ZkAOllrWsLTQXhvHeUNv6PcUdB">
    <img src="https://drive.google.com/uc?export=view&id=1BgD3N7ZkAOllrWsLTQXhvHeUNv6PcUdB" alt="3d_engine_ray_tracing.jpg" style="width: 650px; max-width: 100%; height: auto" title="Click to enlarge picture" />
  </a>
</p>

Plusieurs éléments sont à noter sur la mise en scène :
- Différentes sources de lumières, dont une qui n'est pas hors-champ
- Ombres portées douces, utilisation de quad-lights
- Anti-alliassage : distribution de rayons aléatoires par pixel
- Le lapin de Stanford, le buste et deux sphères sont des maillages
- Une des sphères est décrite analytiquement et le tore est une surface implicite
- Différents matériaux mis en scène : Blinn-Phong, Oren-Nayar et Cook-Torrance
- Réflexion et réfraction : plan mirroir à gauche du lapin, tore mirroir et sphère au dessus du buste transparente
