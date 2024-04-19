
# Importing mosquito population time series into malariasimulation

This is a modified version of Imperial College London's malariasimulation model to import a time series of the daily relative emergence of adult females generated from a separate mosquito metapopulation model, as desribed in Hancock, P.A, North, A et al.. The modifications were made to malariasimulation version 1.4.3 which is available here:
https://github.com/mrc-ide/malariasimulation/releases/tag/v1.4.3

## Installation

Please note, malariasimulation is only compatible with R >= 4.0.0

The package can be installed from github using the "remotes" library. Note, this
method requires [RBuildTools](https://cran.r-project.org/bin/windows/Rtools/)

```R
library('remotes')
install_github('pahanc/malariasimulation_import_mosq')
```

The following R packages are required:
* individual v0.1.12
* malariaEquilibrium 
* malariasimulation v1.4.3"

## Usage

To run this modified version of malariasimulation, files containing site specific model parameters are required. These files are located in the github repository https://github.com/pahanc/inputs-for-malariasimulation_import_mosq . Input files generated from the mosquito metapopulation model developed in Hancock, P.A., North, A. et al. are also required.  These files are in the subdirectories **May 23 stoch** and **May 23 Emerge** .


To run the modified malariasimulation model with the default parameters, you
can execute the function "run_site" :

```R
output <- run_site(square_number=square_number, run_number=run_number, total_M=totalM, human_population=human_population, vaccine_cov=vaccine_cov, PBO=PBO)
```
where
*  **square_number** is the index of the degree square for which site-specific parameters will be obtained. This can be either: 34 (Western Mali),  55 (The Gambia/Senegal),  65 (Southern Mali)  ,82 (Niger/Nigeria), 85 (Senegal/Guinea Bissau) ,112 (Northern Nigeria) ,128 (Western Burkina Faso) ,135 (Benin/Burkina Faso), 182 (Guinea), 236 (Sierra Leone/Liberia), 242 (Cote d'Ivoire), 249 (Togo/Benin), 278 (Nigeria/Lagos) ,288 (Cameroon), 290 (Liberia) , 299 (Ghana)
*  **run_number** indexes which run of the metapopulation model to use to import mosquito suppression and emergence values. There are 25 runs for each degree square area, and run_number can range from 1 to 25.
*  **total_M** is the estimated maximum abundance of the total vector population (including all species) over the simulation period (see Hancock, P. A., North, A. et al.).
*   **human_population** is the number of humans being modelled in a degree-square area.
*   **vaccine_cov** is the coverage of the RTS,S vaccine in the human population
*  **PBO** is a boolean variable indicating whether a switch to using PBO LLINs is made during period over which gene drive releases are assumed to occur.


## License
[MIT](https://choosealicense.com/licenses/mit/)
