#include "commoditycurve.hpp"

#include "utilities.hpp"
#include <ql/currencies/america.hpp>
#include <ql/experimental/commodities/petroleumunitsofmeasure.hpp>
#include <ql/experimental/commodities/commoditycurve.hpp>
#include <ql/experimental/commodities/commodityindex.hpp>
#include <ql/experimental/commodities/energyvanillaswap.hpp>
#include <ql/time/calendars/unitedstates.hpp>
#include <ql/utilities/dataparsers.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
#include <ql/termstructures/yield/flatforward.hpp>

using namespace QuantLib;
using namespace boost::unit_test_framework;




void CommodityCurveTest::test_curve_1() {


	BOOST_TEST_MESSAGE("Testing commodity curves");

	std::vector<Date> dates =
	{ 
		DateParser::parseISO("2017-10-20"),	DateParser::parseISO("2017-11-20"),	DateParser::parseISO("2017-12-19"),	DateParser::parseISO("2018-01-22"),	DateParser::parseISO("2018-02-20"),	DateParser::parseISO("2018-03-20"),	DateParser::parseISO("2018-04-20"),	DateParser::parseISO("2018-05-22"),	DateParser::parseISO("2018-06-20"),	DateParser::parseISO("2018-07-20"),	DateParser::parseISO("2018-08-21"),	DateParser::parseISO("2018-09-20"),	DateParser::parseISO("2018-10-22"),	DateParser::parseISO("2018-11-19"),	DateParser::parseISO("2018-12-19"),	DateParser::parseISO("2019-01-22"),	DateParser::parseISO("2019-02-20"),	DateParser::parseISO("2019-03-20"),	DateParser::parseISO("2019-04-22"),	DateParser::parseISO("2019-05-21"),	DateParser::parseISO("2019-06-20"),	DateParser::parseISO("2019-07-22"),	DateParser::parseISO("2019-08-20"),	DateParser::parseISO("2019-09-20"),	DateParser::parseISO("2019-10-22"),	DateParser::parseISO("2019-11-20"),	DateParser::parseISO("2019-12-19"),	DateParser::parseISO("2020-01-21"),	DateParser::parseISO("2020-02-20"),	DateParser::parseISO("2020-03-20"),	DateParser::parseISO("2020-04-21"),	DateParser::parseISO("2020-05-19"),	DateParser::parseISO("2020-06-22"),	DateParser::parseISO("2020-07-21"),	DateParser::parseISO("2020-08-20"),	DateParser::parseISO("2020-09-22"),	DateParser::parseISO("2020-10-20"),	DateParser::parseISO("2020-11-20"),	DateParser::parseISO("2020-12-21"),	DateParser::parseISO("2021-01-20"),	DateParser::parseISO("2021-02-22"),	DateParser::parseISO("2021-03-22"),	DateParser::parseISO("2021-04-20"),	DateParser::parseISO("2021-05-20"),	DateParser::parseISO("2021-06-22"),	DateParser::parseISO("2021-07-20"),	DateParser::parseISO("2021-08-20"),	DateParser::parseISO("2021-09-21"),	DateParser::parseISO("2021-10-20"),	DateParser::parseISO("2021-11-19"),	DateParser::parseISO("2021-12-20"),	DateParser::parseISO("2022-01-20"),	DateParser::parseISO("2022-02-22"),	DateParser::parseISO("2022-03-22"),	DateParser::parseISO("2022-04-20"),	DateParser::parseISO("2022-05-20"),	DateParser::parseISO("2022-06-21"),	DateParser::parseISO("2022-07-20"),	DateParser::parseISO("2022-08-22"),	DateParser::parseISO("2022-09-20"),	DateParser::parseISO("2022-10-20"),	DateParser::parseISO("2022-11-21"),	DateParser::parseISO("2023-05-22"),	DateParser::parseISO("2023-11-20"),	DateParser::parseISO("2024-05-21"),	DateParser::parseISO("2024-11-20"),	DateParser::parseISO("2025-05-20"),	DateParser::parseISO("2025-11-20"),
	};
	std::vector<Real> prices =
	{
		50.69,	51.04,	51.32,	51.53,	51.66,	51.76,	51.75,	51.68,	51.78,	51.7,	51.42,	51.3,	50.69,	51.23,	50.55,	50.48,	50.41,	50.36,	50.31,	50.78,	50.21,	50.15,	50.1,	50.06,	50.05,	50.5,	50,	49.97,	49.94,	49.92,	49.9,	49.9,	49.88,	49.88,	49.89,	49.92,	49.95,	50.37,	49.98,	49.97,	49.98,	50,	50.03,	50.08,	50.06,	50.07,	50.09,	50.13,	50.19,	50.33,	50.27,	50.29,	50.32,	50.35,	50.41,	50.49,	50.49,	50.51,	50.55,	50.61,	50.68,	50.78,	51.04,	51.36,	51.66,	52.01,	52.33,	52.65
	};
	
	std::map<Date, Real> lookup =
	{
		{ DateParser::parseISO("2017-10-20"),50.69 },{ DateParser::parseISO("2017-11-20"),51.04 },{ DateParser::parseISO("2017-12-19"),51.32 },{ DateParser::parseISO("2018-01-22"),51.53 },{ DateParser::parseISO("2018-02-20"),51.66 },{ DateParser::parseISO("2018-03-20"),51.76 },{ DateParser::parseISO("2018-04-20"),51.75 },{ DateParser::parseISO("2018-05-22"),51.68 },{ DateParser::parseISO("2018-06-20"),51.78 },{ DateParser::parseISO("2018-07-20"),51.7 },{ DateParser::parseISO("2018-08-21"),51.42 },{ DateParser::parseISO("2018-09-20"),51.3 },{ DateParser::parseISO("2018-10-22"),50.69 },{ DateParser::parseISO("2018-11-19"),51.23 },{ DateParser::parseISO("2018-12-19"),50.55 },{ DateParser::parseISO("2019-01-22"),50.48 },{ DateParser::parseISO("2019-02-20"),50.41 },{ DateParser::parseISO("2019-03-20"),50.36 },{ DateParser::parseISO("2019-04-22"),50.31 },{ DateParser::parseISO("2019-05-21"),50.78 },{ DateParser::parseISO("2019-06-20"),50.21 },{ DateParser::parseISO("2019-07-22"),50.15 },{ DateParser::parseISO("2019-08-20"),50.1 },{ DateParser::parseISO("2019-09-20"),50.06 },{ DateParser::parseISO("2019-10-22"),50.05 },{ DateParser::parseISO("2019-11-20"),50.5 },{ DateParser::parseISO("2019-12-19"),50 },{ DateParser::parseISO("2020-01-21"),49.97 },{ DateParser::parseISO("2020-02-20"),49.94 },{ DateParser::parseISO("2020-03-20"),49.92 },{ DateParser::parseISO("2020-04-21"),49.9 },{ DateParser::parseISO("2020-05-19"),49.9 },{ DateParser::parseISO("2020-06-22"),49.88 },{ DateParser::parseISO("2020-07-21"),49.88 },{ DateParser::parseISO("2020-08-20"),49.89 },{ DateParser::parseISO("2020-09-22"),49.92 },{ DateParser::parseISO("2020-10-20"),49.95 },{ DateParser::parseISO("2020-11-20"),50.37 },{ DateParser::parseISO("2020-12-21"),49.98 },{ DateParser::parseISO("2021-01-20"),49.97 },{ DateParser::parseISO("2021-02-22"),49.98 },{ DateParser::parseISO("2021-03-22"),50 },{ DateParser::parseISO("2021-04-20"),50.03 },{ DateParser::parseISO("2021-05-20"),50.08 },{ DateParser::parseISO("2021-06-22"),50.06 },{ DateParser::parseISO("2021-07-20"),50.07 },{ DateParser::parseISO("2021-08-20"),50.09 },{ DateParser::parseISO("2021-09-21"),50.13 },{ DateParser::parseISO("2021-10-20"),50.19 },{ DateParser::parseISO("2021-11-19"),50.33 },{ DateParser::parseISO("2021-12-20"),50.27 },{ DateParser::parseISO("2022-01-20"),50.29 },{ DateParser::parseISO("2022-02-22"),50.32 },{ DateParser::parseISO("2022-03-22"),50.35 },{ DateParser::parseISO("2022-04-20"),50.41 },{ DateParser::parseISO("2022-05-20"),50.49 },{ DateParser::parseISO("2022-06-21"),50.49 },{ DateParser::parseISO("2022-07-20"),50.51 },{ DateParser::parseISO("2022-08-22"),50.55 },{ DateParser::parseISO("2022-09-20"),50.61 },{ DateParser::parseISO("2022-10-20"),50.68 },{ DateParser::parseISO("2022-11-21"),50.78 },{ DateParser::parseISO("2023-05-22"),51.04 },{ DateParser::parseISO("2023-11-20"),51.36 },{ DateParser::parseISO("2024-05-21"),51.66 },{ DateParser::parseISO("2024-11-20"),52.01 },{ DateParser::parseISO("2025-05-20"),52.33 },{ DateParser::parseISO("2025-11-20"),52.65 },

	};

	boost::shared_ptr<CommodityCurve> basic_curve(
		new CommodityCurve("OIL", CommodityType("OIL", "OIL"),
			USDCurrency(),
			BarrelUnitOfMeasure(),
			UnitedStates(UnitedStates::NYSE),
			dates,
			prices,
			Actual360()
		));
	for (auto date : dates)
	{
		Real a_future = basic_curve->price(date);
		Real a_lookup_future = lookup[date];
		if (!close(a_future, a_lookup_future))
		{
			BOOST_FAIL("Interpolation of forward curve does not match for date \n"
				<< "    date:     " << date << "\n"
				<< "    interp: " << a_future << "\n"
				<< "	actual: " << a_lookup_future << "\n");
		}
	};
	boost::shared_ptr<ExchangeContracts> contracts;
	std::string OIL = "foo";
	boost::shared_ptr<CommodityIndex> fake_commodity_future(new CommodityIndex(
		OIL,
		CommodityType("OIL", "OIL"),
		USDCurrency(),
		BarrelUnitOfMeasure(),
		UnitedStates(UnitedStates::NYSE),
		1.0,
		basic_curve,
		contracts,
		0));

	for (auto date : dates)
	{
		Real a_future = fake_commodity_future->forwardPrice(date);
		Real a_lookup_future = lookup[date];
		if (!close(a_future, a_lookup_future))
		{
			BOOST_FAIL("Interpolation of future does not match for date \n"
				<< "    date:     " << date << "\n"
				<< "    interp: " << a_future << "\n"
				<< "	actual: " << a_lookup_future << "\n");
		}
	};

	std::vector<boost::shared_ptr<PricingPeriod>> periods;
	for (auto date : dates)
	{
		periods.push_back(boost::shared_ptr<PricingPeriod>(new PricingPeriod(date, date, date, Quantity(CommodityType("OIL", "OIL"), BarrelUnitOfMeasure(), 1.0))));
	}
		
	boost::shared_ptr<SimpleQuote> flatRate(new SimpleQuote(0.1));
	Handle<Quote> flatRateHandle(flatRate);
	boost::shared_ptr<SecondaryCosts>	costs;
	boost::shared_ptr<YieldTermStructure> basic_term_structure(
		new FlatForward(dates[0], 
			flatRateHandle, Actual360()));
	Handle<YieldTermStructure> basic_term_structure_handle(basic_term_structure);
	boost::shared_ptr<EnergyVanillaSwap> otc_swap(new EnergyVanillaSwap(
		true,
		UnitedStates(UnitedStates::NYSE),
		Money(USDCurrency(), 0.0), // price is 0 at inception
		BarrelUnitOfMeasure(),
		fake_commodity_future,
		USDCurrency(),
		USDCurrency(),
		periods,
		CommodityType("OIL", "OIL"),
		costs,
		basic_term_structure_handle,
		basic_term_structure_handle,
		basic_term_structure_handle));
	auto otc_swap_result = otc_swap->NPV();
	Real handNPV = 0.0;
	for (auto keyval : lookup)
	{
		handNPV = handNPV + keyval.second*basic_term_structure_handle->discount(keyval.first);
	}

	if (!close(handNPV, otc_swap_result))
	{
		BOOST_FAIL("OTC SWAP and strip of forwards do not match \n"
			<< "    OTC SWAP: " << otc_swap_result << "\n"
			<< "	forwards: " << handNPV << "\n");
	}
}

test_suite* CommodityCurveTest::suite() {
	test_suite* suite = BOOST_TEST_SUITE("Commodity Curve tests");
	suite->add(QUANTLIB_TEST_CASE(&CommodityCurveTest::test_curve_1));
	return suite;
}

