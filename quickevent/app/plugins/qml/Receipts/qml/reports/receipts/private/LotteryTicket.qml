import QtQml 2.0
import qf.qmlreports 1.0
import shared.QuickEvent.reports 1.0
import "qrc:/qf/core/qml/js/timeext.js" as TimeExt
import "qrc:/quickevent/core/js/ogtime.js" as OGTime

Frame {
	//visible: false
	hinset: 1
	vinset: 1
	Frame {
		width: "%"
		layout: Frame.LayoutHorizontal
		textStyle: myStyle.textStyleBold
		bottomBorder: Pen { basedOn: "black2" }
		htmlExportAttributes: {"lpt_textStyle": "bold,underline2"}
		Para {
			width: "%"
			text: detailCompetitor.data(detailCompetitor.currentIndex, "classes.name") + " " + detailCompetitor.data(detailCompetitor.currentIndex, "competitorName")
		}
		Para {
			textHAlign: Frame.AlignRight
			htmlExportAttributes: {"lpt_textWidth": "%", "lpt_textAlign": "right"}
			text: {
				var t = detailCompetitor.data(detailCompetitor.currentIndex, "competitors.registration");
				return (t)? t: "NO_REG";
			}
		}
	}
	Frame {
		width: "%"
		vinset: 1
		halign: Frame.AlignHCenter
		htmlExportAttributes: {"lpt_textWidth": "%", "lpt_textAlign": "center"}
		Para {
			htmlExportAttributes: {"lpt_textStyle": "bold"}
			textStyle: myStyle.textStyleBold
			text: "Slosovatelný kupón";
		}
		Para {
			htmlExportAttributes: {"lpt_textStyle": "bold"}
			textStyle: myStyle.textStyleBold
			text: "Každé vyhlášení - 3x hodinky";
		}
		Frame { height: 2 }
		Frame {
			layout: Frame.LayoutHorizontal
			valign: Frame.AlignVCenter
			Frame {
				width: "%"
				bottomBorder: Pen { basedOn: "black1dot" }
				//htmlExportAttributes: {"lpt_text": "-----"}
			}
			Para {
				text: "zde odstřihnout";
			}
			Frame {
				width: "%"
				bottomBorder: Pen { basedOn: "black1dot" }
				//htmlExportAttributes: {"lpt_text": "-----"}
			}
		}
		Frame { height: 2 }
		Para {
			textStyle: myStyle.textStyleBold
			text: "Čip + buzola = ComCard.";
		}
		Para {
			halign: Frame.AlignHCenter
			text: "Rychlé ražení.";
		}
		Para {
			halign: Frame.AlignHCenter
			text: "Žádné zastrkávání, stačí přiložit.";
		}
		Para {
			halign: Frame.AlignHCenter
			text: "Zvládnete to jedním prstem.";
		}
		Para {
			htmlExportAttributes: {"lpt_textStyle": "bold"}
			halign: Frame.AlignHCenter
			text: "Se slevou ve stánku HSH";
			textStyle: myStyle.textStyleBold
		}
	}
}
