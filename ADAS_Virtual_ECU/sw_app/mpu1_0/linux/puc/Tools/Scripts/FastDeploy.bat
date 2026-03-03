@echo off

@rem #--------------------------------------------------------------------------------#
@rem #              __                                                                #
@rem #             //\\               (C) Copyright 2019                              #
@rem #             \\//                                                               #
@rem #                                Magna Electronics Europe GmbH & Co. OHG         #
@rem #          \\\\\ \\\\\                                                           #
@rem #        /\ \\\\\ \\\\\          Am Saegewerk 10                                 #
@rem #       //\\ \\\\\ \\\\\         63773 Goldbach, Germany                         #
@rem #      ///\\\ \\\\\ \\\\\        All rights reserved.                            #
@rem #     ////\\\\ \\\\\ \\\\\                                                       #
@rem #    /////\\\\\ \\\\\ \\\\\      http://www.magna.com                            #
@rem #                                                                                #
@rem #--------------------------------------------------------------------------------#
@rem #    MAGNA Electronics - C O N F I D E N T I A L                                 #
@rem #      This document in its entirety is CONFIDENTIAL and may not be              #
@rem #      disclosed, disseminated or distributed to parties outside MAGNA           #
@rem #      Electronics without written permission from MAGNA Electronics.            #
@rem #--------------------------------------------------------------------------------#
@rem #    Created on: 19.03.2019                                                      #
@rem #      Author: Roman Berngardt (Roman.Berngardt@magna.com)                       #
@rem #--------------------------------------------------------------------------------#

@title Toyota_780B PuC Deploy SW stack over JTAG to RAM

@set CURDIR=%CD%
@call %CURDIR%\Deployment\Deploy_SW.bat