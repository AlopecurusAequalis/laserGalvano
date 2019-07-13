int getMotorXreference(int step){
   const int motorXreference[] = {7975,7980,7985,7990,7995,8000,8005,8010,8015,8020,8025,8030,8035,8041,8046,8051,8056,8061,8066,8071,8076,8081,8086,8091,8096,8101,8106,8111,8116,8121,8126,8131,8137,8142,8147,8152,8157,8162,8167,8172,8177,8182,8182,8187,8192,8192,8197,8197,8202,8202,8207,8207,8212,8212,8212,8212,8217,8217,8217,8217,8217,8222,8222,8222,8222,8222,8222,8222,8222,8222,8222,8222,8222,8217,8217,8217,8217,8217,8212,8212,8212,8207,8207,8207,8202,8202,8197,8197,8192,8192,8187,8182,8177,8177,8172,8167,8162,8157,8152,8147,8142,8137,8131,8126,8121,8116,8111,8106,8101,8096,8091,8086,8081,8076,8071,8066,8061,8056,8051,8046,8041,8035,8030,8025,8020,8015,8010,8005,8000,7995,7990,7985,7980,7975,7970,7965,7959,7954,7949,7944,7939,7934,7929,7924,7919,7914,7909,7904,7899,7894,7889,7884,7879,7874,7869,7863,7858,7853,7848,7843,7838,7833,7828,7828,7823,7818,7818,7813,7813,7808,7808,7803,7803,7803,7798,7798,7798,7793,7793,7793,7793,7793,7788,7788,7788,7788,7788,7788,7788,7788,7788,7788,7788,7788,7793,7793,7793,7793,7793,7798,7798,7798,7803,7803,7803,7808,7808,7813,7813,7818,7818,7823,7828,7828,7833,7838,7843,7848,7853,7858,7863,7869,7874,7879,7884,7889,7894,7899,7904,7909,7914,7919,7924,7929,7934,7939,7944,7949,7954,7959,7965,7970};
  // const int motorXreference[] = {7962,8008,8053,8099,8144,8189,8234,8272,8302,8317,8324,8331,8331,8317,8302,8279,8242,8197,8152,8106,8061,8015,7970,7924,7879,7833,7788,7743,7721,7698,7691,7683,7683,7691,7706,7728,7766,7811,7856,7901};
  //const int motorXreference[] = {7987,8003,8018,8033,8048,8063,8078,8091,8101,8106,8109,8111,8111,8106,8101,8094,8081,8066,8051,8035,8020,8005,7990,7975,7959,7944,7929,7914,7906,7899,7896,7894,7894,7896,7901,7909,7922,7937,7952,7967};
  return motorXreference[step] - 3400;
}
int getMotorYreference(int step){
  // const int motorYreference[] = {7777,7777,7777,7777,7777,7777,7777,7777,7777,7777,7777,7777,7777,7782,7782,7782,7782,7782,7787,7787,7787,7792,7792,7797,7797,7802,7802,7808,7808,7813,7813,7818,7823,7828,7833,7839,7844,7849,7854,7859,7865,7870,7875,7880,7885,7891,7896,7901,7906,7911,7917,7922,7927,7932,7937,7943,7948,7953,7958,7963,7969,7974,7979,7984,7990,7995,8000,8005,8010,8016,8021,8026,8031,8037,8042,8047,8052,8057,8063,8068,8073,8078,8083,8089,8094,8099,8104,8109,8115,8120,8125,8130,8135,8141,8146,8151,8156,8161,8167,8172,8177,8182,8187,8187,8192,8198,8198,8203,8203,8208,8208,8213,8213,8218,8218,8218,8218,8223,8223,8223,8223,8229,8229,8229,8229,8229,8229,8229,8229,8229,8229,8229,8229,8223,8223,8223,8223,8223,8218,8218,8218,8218,8213,8213,8208,8208,8203,8203,8198,8198,8192,8187,8187,8182,8177,8172,8167,8161,8156,8151,8146,8141,8135,8130,8125,8120,8115,8109,8104,8099,8094,8089,8083,8078,8073,8068,8063,8057,8052,8047,8042,8037,8031,8026,8021,8016,8010,8005,8000,7995,7990,7984,7979,7974,7969,7963,7958,7953,7948,7943,7937,7932,7927,7922,7917,7911,7906,7901,7896,7891,7885,7880,7875,7870,7865,7859,7854,7849,7844,7839,7833,7828,7823,7818,7818,7813,7808,7808,7802,7802,7797,7797,7792,7792,7787,7787,7787,7782,7782,7782,7782,7782};
  // const int motorYreference[] = {7666,7666,7666,7682,7697,7720,7766,7813,7859,7906,7953,8000,8047,8094,8141,8187,8234,8280,8303,8326,8334,8341,8341,8326,8311,8288,8249,8203,8156,8109,8063,8016,7969,7922,7875,7828,7782,7735,7705,7682};
  const int motorYreference[] = {7888,7888,7888,7893,7898,7906,7922,7937,7953,7969,7984,8000,8016,8031,8047,8063,8078,8094,8102,8109,8112,8115,8115,8109,8104,8096,8083,8068,8052,8037,8021,8005,7990,7974,7958,7943,7927,7911,7901,7893};
  return motorYreference[step] - 300;
}
int genStepSignal(int step, int squarePeriod){
  if (step > squarePeriod/2){
    return 4000;
  }else{
    return 5000;
  }
}
