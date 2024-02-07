
# Importing mosquito population time series into malariasimulation

This is a modified version of Imperial College London's malariasimulation model to import a time series of the daily relative emergence of adult females generated from a separate mosquito metapopulation model, as desribed in Hancock, P.A, North, A et al.. The modifications were made to malariasimulation version 1.4.3 which is available here:
https://github.com/mrc-ide/malariasimulation/releases/tag/v1.4.3

## Installation

Please note, malariasimulation is only compatible with R >= 4.0.0

The package canbe installed from github using the "remotes" library. Note, this
method requires [RBuildTools](https://cran.r-project.org/bin/windows/Rtools/)

```R
library('remotes')
install_github('pahanc/malariasimulation_import_mosq')
```

The following R packages are required:
*individual v0.1.12
*malariaEquilibrium 
*malariasimulation v1.4.3"

## Usage

To run this modified version of malariasimulation, input files generated from the mosquito metapopulation model developed in Hancock, P.A., North, A. et al. are required. These files are located here: 
In addition, files containing site specific model parameters are required. These files are located and described here:

To run the modified malariasimulation model with the default parameters, you
can execute the function run_site() which is located here:

```R
output <- run_site()
```



## License
[MIT](https://choosealicense.com/licenses/mit/)
