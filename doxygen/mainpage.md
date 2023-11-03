\mainpage 
<div style="text-align: center;">
    <img src="onion.png" alt="OnionFW logo" style="width: 100px; height: 100px; padding-top:30px;">
</div>
<div style="text-align: center; padding:0; margin:0; border:0;">
    <h1>Onion Framework</h1>
    <img alt="released" src="https://img.shields.io/static/v1?label=Released&message=Apr 26 2023&color=orange&style=for-the-badge&logo=github&logoColor=white">
    <img alt="version" src="https://img.shields.io/static/v1?label=Version&message=0.1.0 build 14&color=success&style=for-the-badge&logo=github&logoColor=white">
    <img alt="licence" src="https://img.shields.io/static/v1?label=License&message=MIT&color=blue&style=for-the-badge">
</div>
<hr>

\section intro_sec Introduction

Work in progress

<hr>
\section install_sec Installation

\subsection step1 Step 1: Opening the box

Work in progress

<hr>
\section design Design Principles

The Onion Framework is structured around components that are

 - Uncoupled (independent of each other) by design.
 - Associable (may connected to each other) if, and only if, required.
 - Simple: Each component **must** have a single and well defined responsibility.
 - Extensible and reusable.

 Achieve these properties simultaneously demands carefull design and a considerable software engineering effort,
 but it results in the virtues we were looking for when we started this work.

  - Scalability: new components are added and combined with the existing ones, not recreated.
  - Reusable code: abstractions, uncoupling and single responsability results in highly reusable code.
  - Reproduction of results: clearly defined components and algorithms make
    code interpretation and reproduction much easier.
  - Performance attribution: separation of concerns and clear boudaries induced by
    components make easier to attrubute and measure performance.
