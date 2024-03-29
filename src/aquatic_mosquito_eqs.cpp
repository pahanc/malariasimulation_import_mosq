/*
 * mosquito_ode.cpp
 *
 *  Created on: 11 Jun 2020
 *      Author: gc1610
 */

#include <Rcpp.h>
#include "aquatic_mosquito_eqs.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

integration_function_t create_eqs(AquaticMosquitoModel& model) {
    return [&model](const state_t& x, state_t& dxdt, double t) {
//The aquatic mosquito model is not updated. The model is used to initialize the numbers of pupae.        
    };

}

AquaticMosquitoModel::AquaticMosquitoModel(
    double beta,
    double de,
    double mue,
    double K0,
    double gamma,
    double dl,
    double mul,
    double dp,
    double mup,
    size_t total_M,
    bool model_seasonality,
    double g0,
    std::vector<double> g,
    std::vector<double> h,
    double R_bar,
    double mum,
    double f,
    double rainfall_floor
    ):
    beta(beta),
    de(de),
    mue(mue),
    K0(K0),
    gamma(gamma),
    dl(dl),
    mul(mul),
    dp(dp),
    mup(mup),
    total_M(total_M),
    model_seasonality(model_seasonality),
    g0(g0),
    g(g),
    h(h),
    R_bar(R_bar),
    mum(mum),
    f(f),
    rainfall_floor(rainfall_floor)
    {}



//[[Rcpp::export]]
Rcpp::XPtr<AquaticMosquitoModel> create_aquatic_mosquito_model(
    double beta,
    double de,
    double mue,
    double K0,
    double gamma,
    double dl,
    double mul,
    double dp,
    double mup,
    size_t total_M,
    bool model_seasonality,
    double g0,
    std::vector<double> g,
    std::vector<double> h,
    double R_bar,
    double mum,
    double f,
    double rainfall_floor
    ) {
    auto model = new AquaticMosquitoModel(
        beta,
        de,
        mue,
        K0,
        gamma,
        dl,
        mul,
        dp,
        mup,
        total_M,
        model_seasonality,
        g0,
        g,
        h,
        R_bar,
        mum,
        f,
        rainfall_floor
    );
    return Rcpp::XPtr<AquaticMosquitoModel>(model, true);
}

//[[Rcpp::export]]
void aquatic_mosquito_model_update(
    Rcpp::XPtr<AquaticMosquitoModel> model,
    size_t total_M,
    double f,
    double mum
    ) {
    model->total_M = total_M;
    model->f = f;
    model->mum = mum;
}


//[[Rcpp::export]]
Rcpp::XPtr<Solver> create_aquatic_solver(
    Rcpp::XPtr<AquaticMosquitoModel> model,
    std::vector<double> init,
    double r_tol,
    double a_tol,
    size_t max_steps
    ) {
    return Rcpp::XPtr<Solver>(
        new Solver(init, create_eqs(*model), r_tol, a_tol, max_steps),
        true
    );
}
