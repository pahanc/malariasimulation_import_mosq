[![R build status](https://github.com/mrc-ide/malariasimulation/workflows/R-CMD-check/badge.svg)](https://github.com/mrc-ide/malariasimulation/actions)
[![codecov](https://codecov.io/github/mrc-ide/malariasimulation/branch/master/graphs/badge.svg)](https://codecov.io/github/mrc-ide/malariasimulation)

# Importing mosquito population time series into malariasimulation

This is a modified version of Imperial College London's malariasimulation model to import a time series of the daily relative emergence of adult females, as desribed in Hancock, P.A, North, A et al.. The modifications were made to malariasimulation version 1.4.3 which is available here:
https://github.com/mrc-ide/malariasimulation/releases/tag/v1.4.3

## Installation

Please note, malariasimulation is only compatible with R >= 4.0.0



The package can also be installed from github using the "remotes" library. Note, this
method requires [RBuildTools](https://cran.r-project.org/bin/windows/Rtools/)

```R
library('remotes')
install_github('pahanc/malariasimulation_import_mosq')
```

The following R packages are required:
"mrc-ide/individual"
"mrc-ide/malariaEquilibrium"
"mrc-ide/malariasimulation@v1.4.3"

## Usage

To run the malaria simulation with the default parameters for 100 timesteps, you
can execute the following code:

```R
library('malariasimulation')

output <- run_simulation(100)
```

## Code organisation

*model.R* - is the entry point for the model. It creates the different
components and passes them to the `individual` package for simulation.

*variables.R* - contains the specific variables we track for each individual.

*processes.R* - defines the changes in individuals over time. It collects
process functions from "infection.R", "mosquito_emergence.R" and "mortality.R"

*tests* - are divided into unit and integration tests. Integration tests are
strongly recommended for large process functions and unit tests for model
calculations.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to
discuss what you would like to change.

Please make sure to update tests and documentation as appropriate.

Code reviews will be carried out in-line with RESIDE-IC's [review
process](https://reside-ic.github.io/articles/pull-requests/)

## License
[MIT](https://choosealicense.com/licenses/mit/)
